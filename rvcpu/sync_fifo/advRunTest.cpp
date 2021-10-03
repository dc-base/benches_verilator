#include "Vsync_fifo.h"
#include "verilated.h"
#include <verilated_vcd_c.h>
#include <limits.h>
#include <queue>
#include <time.h>
#include <stdlib.h>
//Borrowed template from zipcpu, custom modified.
//template operations on generic types (takes a class type)
//sync_fifo(clk, rst, write,  read, wData, rdData, empty, full
template<class MODULE> class TESTBENCH {
	int clocks;
	
	VerilatedVcdC *trace;
	
	MODULE *top;
	
	queue<int> checker;
	public: TESTBENCH(void) {
		top = new MODULE;
		Verilated::traceEverOn(true);
		clocks = 0;
	}
	public: virtual ~TESTBENCH(void){
		delete top;
		top = NULL;
	}
	public: void openTrace(const char *vcdName){
		if(!trace){
			trace = new VerilatedVcdC;
			top->trace(trace, 99);
			trace->open(vcdName);
		}
	}
	public: void closeTrace(void){
		if(trace) {
			trace->close();
			trace = NULL;
		}
	}
	public: virtual void reset(void){
		printf("[RESET]\n"); 
		top->rst = 0;
		this->tick();
		top->rst = 1;
	}
	public: virtual void tick(void){
		clocks++;
		top->clk = 0;
		top->eval();
		if(trace) trace->dump(10*clocks-2);
		top->clk = 1;
		top->eval();
		if(trace) trace->dump(10*clocks);
		top->clk = 0;
		top->eval();
		if(trace){
			trace->dump(10*clocks+5);
			trace->flush();
		}
		//clocks++;
	}
	public: virtual int getClocks(){
		return clocks;
	}	
	public: virtual bool done(void){
		return Verilated::gotFinish();
	}
	public: virtual void writeData(int data){
		printf("writing %d\n", data);
		top->wData = data;
		top->write = 1;
		//top->wData = 0x11111111;
		top->wData = data;
		tick();
		top->write = 0;
		checker.push(data);
	}
	public: virtual void readData() {
		top->read = 1;
		tick();
		int dataRead = top->rdData;	
		printf("Read: %d\n", dataRead);
		top->read = 0;
		if(dataRead != checker.pop()) {
			printf("[ERROR] read data does not match internal FIFO");
		}
	}
	
	public: virtual void rwData(int data) {
		top->read = 1;
		top->write = 1;
		top->wData = data;
		tick();
		int dataRead = top->rdData;
		printf("Write: %d, Read: %d", data, dataRead);
		top->read = 0;
		checker.push(data);
		if(dataRead != checker.pop()) {
			printf("[ERROR] read data does not match internal FIFO");
		}
	}

};
#define MAX_CLOCKS 50
#define RAND_SIZE 3
int main(int argc, char** argv){
	Verilated::commandArgs(argc, argv);
	TESTBENCH<Vsync_fifo> *bench = new TESTBENCH<Vsync_fifo>();
 	bench->openTrace("Dump.vcd");	
	srand (time(NULL)); //init seed
	int num = rand() % 2;
	bench->reset();
	while(bench->getClocks() < MAX_CLOCKS) {	
		switch(num){
			case:0 : bench->writeData(rand() % INT_MAX);
				break;
			case:1 : bench->readData();
				break;
			case:2 bench->rwData(rand() % INT_MAX);
				break;
		}
	}

	//bench->writeData(INT_MAX);
	//bench->writeData(INT_MIN);
	//bench->readData();
	//bench->readData();	
	//while (!bench->done() && bench->getClocks() <= MAX_CLOCKS) {
	//	bench->tick();
	//	printf("[CLOCK] : %d", bench->getClocks());
	//}
	bench->closeTrace(); 
	printf("\n");
	exit(EXIT_SUCCESS);
	return 0;
}

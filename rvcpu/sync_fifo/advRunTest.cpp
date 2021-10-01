#include "Vsync_fifo.h"
#include "verilated.h"
#include <verilated_vcd_c.h>
//Borrowed template from zipcpu, custom modified.
//template operations on generic types (takes a class type)
//sync_fifo(clk, rst, write,  read, wData, rdData, empty, full
template<class MODULE> class TESTBENCH {
	int clocks;
	
	VerilatedVcdC *trace;
	
	MODULE *top;
	
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
		top->wData = 0;
		top->write = 0;
		tick();
	}
	public: virtual unsigned int readData() {
		int dataRet;
		top->clk = 0;
		top->eval();
		top->read = 1;
		top->clk = 1;
		dataRet = top->rdData;
		top->eval();
		top->clk = 0;
		top->eval();
		clocks++;
		return dataRet;
	}
	
	public: virtual unsigned int rwData(int data) {
		int dataRet;
		top->clk = 0;
		top->eval();
		top->write = 1;
		top->read = 1;
		top->wData = data;
		top->clk = 1;
		dataRet = top->rdData;
		top->eval();
		top->clk = 0;
		top->wData = 0;
		top->write = 0;
		top->read = 0;
		top->eval();
		clocks++;
		return dataRet;
	}

};
#define MAX_CLOCKS 50
int main(int argc, char** argv){
	Verilated::commandArgs(argc, argv);
	TESTBENCH<Vsync_fifo> *bench = new TESTBENCH<Vsync_fifo>();
 	bench->openTrace("Dump.vcd");	
	bench->reset();	
	bench->writeData(5);
	printf("Read: %d\n", bench->readData());
	
	//while (!bench->done() && bench->getClocks() <= MAX_CLOCKS) {
	//	bench->tick();
	//	printf("[CLOCK] : %d", bench->getClocks());
	//}
	bench->closeTrace(); 
	printf("\n");
	exit(EXIT_SUCCESS);
	return 0;
}

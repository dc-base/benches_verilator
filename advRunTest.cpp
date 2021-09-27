#include "Vsync_fifo.h"
#include "verilated.h"
//Borrowed templated from zipcpu, custom modified.
//templace operations on generic types (takes a class type)
template<class MODULE> class TESTBENCH {
	int clocks;
	MODULE *top;

	public: TESTBENCH(void) {
		top = new MODULE;
		clocks = 0;
	}
	public: virtual ~TESTBENCH(void){
		delete top;
		top = NULL;
	}
	public: virtual void reset(void){
		printf("[RESET]\n"); 
		top->rst = 0;
		this->tick();
		top->rst = 1;
	}
	public: virtual void tick(void){
		top->clk = 0;
		top->eval();
		top->clk = 1;
		top->eval();
		top->clk = 0;
		top->eval();
		clocks++;
	}
	public: virtual int getClocks(){
		return clocks;
	}	
	public: virtual bool done(void){
		return Verilated::gotFinish();
	}

};
#define MAX_CLOCKS 50
int main(int argc, char** argv){
	Verilated::commandArgs(argc, argv);
	TESTBENCH<Vsync_fifo> *bench = new TESTBENCH<Vsync_fifo>();
 	
	bench->reset();	
	while (!bench->done() && bench->getClocks() <= MAX_CLOCKS) {
		bench->tick();
		printf("[CLOCK] : %d", bench->getClocks());
	} 
	printf("\n");
	exit(EXIT_SUCCESS);
	return 0;
}

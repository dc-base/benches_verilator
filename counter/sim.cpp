#include "Vcounter_top.h"
#include "verilated.h"
int main(int argc, char** argv, char** env){
	VerilatedContext* contextp = new VerilatedContext;
	contextp->commandArgs(argc, argv);
	Vcounter_top* top = new Vcounter_top{contextp};

	int clkcount = 0;
	//run for 50 clocks
	while (!contextp->gotFinish() && clkcount < 50) {
		top->clk = 1;
		top->eval();
		top->clk = 0;
		top->eval();
		clkcount++;
	} exit(EXIT_SUCCESS);
	delete top;
	delete contextp;
	return 0;
}

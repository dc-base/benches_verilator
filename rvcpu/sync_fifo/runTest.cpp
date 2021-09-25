#include "Vsync_fifo.h"
#include "verilated.h"

#define MAX_CLOCKS 50
int main(int argc, char** argv, char** env){
	VerilatedContext* contextp = new VerilatedContext;
	contextp->commandArgs(argc, argv);
	Vsync_fifo* top = new Vsync_fifo{contextp};
	//Add some sort of clock limit so we do not get stuck infinite
	int clk_cnt = 0;
	while (!contextp->gotFinish() && clk_cnt < MAX_CLOCKS) {
		top->clk = 0;
		top->eval();
		top->clk = 1;
		top->eval();
		clk_cnt++;
	}

	delete top;
	delete contextp;
	return 0;
}

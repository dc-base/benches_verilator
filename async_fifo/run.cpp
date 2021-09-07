#include "Vtop.h"
#include "verilated.h"

#define MAX_CLOCKS 50

int main(int argc, char** argv, char** env){
	VerilatedContext* contextp = new VerilatedContext;
	contextp->commandArgs(argc, argv);
	Vtop* top = new Vtop{contextp};
	//Add some sort of clock limit so we do not get stuck infinite
	int clk_cnt = 0;
	top->rst = 0;
	top->eval();	
	top->rst = 1;
	top->eval();
	top->re = 0;
	top->we = 0;

	while (!contextp->gotFinish() && clk_cnt < MAX_CLOCKS) {
		top->eval();
		top->w_clk = 1;
		top->din = 0b10101010;
		top->eval();
		clk_cnt++;
		top->w_clk = 0;
	}

	delete top;
	delete contextp;
	return 0;
}

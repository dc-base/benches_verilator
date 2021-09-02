#include "Vtop_ddr.h"
#include "verilated.h"
int main(int argc, char** argv, char** env){
	VerilatedContext* contextp = new VerilatedContext;
	contextp->commandArgs(argc, argv);
	Vtop_ddr* top = new Vtop_ddr{contextp};
	while (!contextp->gotFinish()) {top->eval();}
	delete top;
	delete contextp;
	return 0;
}

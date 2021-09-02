#!/bin/bash

if [ $# -ne 2 ]; then
	printf "Usage:\nmk_verilator_bench {top_module_name} {destination_name}\n"
	exit 0
fi
cat >> $2.cpp <<EOL
#include "V$1.h"
#include "verilated.h"
int main(int argc, char** argv, char** env){
	VerilatedContext* contextp = new VerilatedContext;
	contextp->commandArgs(argc, argv);
	V$1* top = new V$1{contextp};
	while (!contextp->gotFinish()) {top->eval();}
	delete top;
	delete contextp;
	return 0;
}
EOL

printf "Using $1 top module, new skeleton verilator bench is in $2.cpp\n"
exit 0

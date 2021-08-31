#!/bin/bash

if [ $# -ne 2 ]; then
	#echo "Usage: \n sim_sv {Cfile.cpp} {top_module.sv}"

	printf "Usage:\nsim_sv {Cfile.cpp} {top_module.sv}"
	exit 0
fi

verilator -Wall -cc --exe --build ${1} ${2}"

obj_dir/V$1
exit 0

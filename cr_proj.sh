#!/bin/bash

if [ $# -ne 1 ]; then
	printf "Usage: cr_proj {name}\n"
	printf "Dependencies: mk_ver_bench & sim_sv in same directory\n"
	exit 0
fi

mkdir $1
cd $1
cp ../mk_ver_bench .
cp ../sim_sv .

exit 0



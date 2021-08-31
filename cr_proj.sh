#!/bin/bash

if [ $# -ne 1 ]; then
	printf "Usage: cr_proj {name}\n"
	printf "Dependencies: mk_ver_bench.sh & sim_sv.sh in same directory\n"
	exit 0
fi

mkdir $1
cd $1
cp ../mk_ver_bench.sh .
cp ../sim_sv.sh .

exit 0



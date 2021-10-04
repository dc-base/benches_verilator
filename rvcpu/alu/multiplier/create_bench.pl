#!/bin/perl

if(@ARGV != 1){ #or $ARGV or $#ARGV
	print "Usage perl create_bench.pl [top_module_name]\n";
	exit 0
}

$top = @ARGV[0];
#$top =~ s/[.].*//;

print "$top\n";
sub createBench{
	my $name = @_;
	
	my $removeExt = sub{$name =~ s/[.].*//};
	
	&$removeExt();
	print $name;

			
	open(TM, ">advRunTest.cpp") or die "unable to open advRunTest.cpp";
	$writeOut = <<"EOF";
	#include "V$top.h"
	#include "verilated.h"
	#include <verilated_vcd_c.h>
	#include <limits.h>
	
	
	//template operations on generic types (takes a class type)
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
			printf("[RESET]\\n"); 
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
	};
	#define MAX_CLOCKS 50
	int main(int argc, char** argv){
		Verilated::commandArgs(argc, argv);
		TESTBENCH<V$top> *bench = new TESTBENCH<V$top>();
	 	bench->openTrace("dump.vcd");	
		bench->reset();	
		
	
	
		//while (!bench->done() && bench->getClocks() <= MAX_CLOCKS) {
		//	bench->tick();
		//	printf("[CLOCK] : %d", bench->getClocks());
		//}
		bench->closeTrace(); 
		printf("\\n");
		exit(EXIT_SUCCESS);
		return 0;
	}
	EOF
	
	print TM $writeOut;
};

createBench($top);
exit 0

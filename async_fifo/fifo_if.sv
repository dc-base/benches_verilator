`timescale 1ns/1ps

interface fifo_if #(
	parameter DATA_WIDTH = 8
	)	
	(
		input w_clk, 
		input r_clk, 
		input rst
	);
	logic [DATA_WIDTH-1:0] din;
        logic [DATA_WIDTH-1:0] dout;
	logic full;
        logic empty;
	logic re;
	logic we;

	modport DUT(input din, output dout, input re, input we, output full, output empty, r_clk, w_clk, rst);
endinterface



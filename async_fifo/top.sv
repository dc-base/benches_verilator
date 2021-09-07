`timescale 1ns/1ps

`include "async_fifo_no_intf.sv"
`include "fifo_if.sv"

//interface fifo_if #(
//	parameter DATA_WIDTH = 8
//	)	
//	(
//		input w_clk, 
//		input r_clk, 
//		input rst
//	);
//	logic [DATA_WIDTH-1:0] din, dout;
//	logic full, empty;
//	logic re,we;
//
//	//modport DUT(input din, output dout, input re, input we, output full, output empty, r_clk, w_clk, rst);
//endinterface

module top(
	w_clk,
	r_clk,
	rst,
	we,
	re,
	full,
	empty,
	din,
	dout
);

localparam width = 8;
localparam depth = 5;
localparam pntr_width = 3;

input logic w_clk, r_clk, we, re, rst;
input logic[width - 1:0] din;
output logic[width - 1:0] dout;
output logic full, empty;

initial begin
	$display("Compiled Correctly");
end

//fifo_if t_if(.w_clk(w_clk), .r_clk(r_clk), .rst(rst));

//async_fifo #(.PNTR_WIDTH(pntr_width), .DATA_WIDTH(width), .FIFO_DEPTH(depth)) 
//	fifo1(.mif(t_if.DUT));
async_fifo_no_intf #(.PNTR_WIDTH(pntr_width), .DATA_WIDTH(width), .FIFO_DEPTH(depth)) 
	fifo(w_clk, r_clk, re, we, rst, din, dout, full, empty);


//defparam fifo.PNTR_WIDTH = 3;
//defparam fifo.DATA_WIDTH = width;
//defparam fifo.FIFO_DEPTH = depth;

endmodule

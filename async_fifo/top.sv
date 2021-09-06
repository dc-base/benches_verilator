`timescale 1ns/1ps

`include "async_fifo.sv"

module top(
	w_clk,
	r_clk,
	we,
	re,
	din,
	rst,
	dout,
	full,
	empty
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

async_fifo #(.PNTR_WIDTH(pntr_width), .DATA_WIDTH(width), .FIFO_DEPTH(depth)) 
	fifo(w_clk, r_clk, re, we, rst, din, dout, full, empty);


//defparam fifo.PNTR_WIDTH = 3;
//defparam fifo.DATA_WIDTH = width;
//defparam fifo.FIFO_DEPTH = depth;

endmodule

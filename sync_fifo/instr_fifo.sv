`timescale 1ns/1ps

module instr_fifo(
	input clk,
	input rst,
	input din,
	input wr,
	input rr,
	output empty,
	output full,
	output dout
);
parameter DATA_WIDTH = 8;
parameter FIFO_DEPTH = 8;
logic [DATA_WIDTH - 1:0] din;
logic [DATA_WIDTH - 1:0] dout;

logic [DATA_WIDTH - 1:0] FIFO [0:FIFO_DEPTH - 1]
integer unsigned ptr;
always@(posedge clk or negedge rst) begin
	if(~rst) begin
		ptr = 0;
	end
	else if(rr && ptr != 0) begin
		dout = FIFO[ptr];
		ptr = ptr - 1;
	end
	else if(wr && ptr < FIFO_DEPTH - 1) begin
		ptr = ptr + 1;
		FIFO[ptr] = din;
	end
end
endmodule


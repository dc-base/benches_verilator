`timescale 1ns/1ps

module ddr_ctrl(
	input clk_n, 
	input clk_p,
	input we,
	input re,
	inout [63:0] DQ,
	inout DQS,
	input [31:0] addr
);

struct {
	bit we;
	bit[31:0] address;
}buffer_item;
buffer_item buffer[$]
always@(posedge clk) begin
	if(we) begin
		buffer.push_back({we, addr});
	end
	end
endmodule




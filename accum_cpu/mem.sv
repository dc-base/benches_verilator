`timescale 1ns/1ps

module mem(input clk,
        input re,
	input we,
	input [0:5] addr,
	output wr,
	output byte unsigned dout
);

byte unsigned arr[0:7] [0:7];

bit[0:2] row;
bit[0:2] col;

assign row = addr[0:2];
assign col = addr[3:5];
always@(posedge clk) begin
	if(re) begin
		dout = arr[row][col];
	end
end




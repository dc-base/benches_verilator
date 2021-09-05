`timescale 1ns/1ps

module mem(input clk,
        input re,
	input we,
	input [0:5] addr,
	output wr,
	output byte unsigned dout
);
//8x8 single bank  
byte unsigned arr[0:7];

always@(posedge clk) begin
	if(re) begin
		dout = arr[row][col];
	end
end




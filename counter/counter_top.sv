`timescale 1ns/1ps

`include "./counter.sv"
module counter_top(
	input logic clk,
	output byte count
);
	counter counter_inst(clk, count);
	always@(posedge clk) begin
		$display(count);
	end
	endmodule


	

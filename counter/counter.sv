`timescale 1ns/1ps

module counter(input logic clk, output byte count);
	
	always_ff @(posedge clk) begin
		if(count == 127) begin
			count <= 0;
		end
		else begin
			count <= count + 1;
		end
	end 
	endmodule

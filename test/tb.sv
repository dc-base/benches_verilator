`timescale 1ns/1ps

module testbench;

logic clk;

initial begin
	logic clk = 0;
	forever #5 clk = !clk;
	
	top test_inst(clk);	
end

endmodule:testbench

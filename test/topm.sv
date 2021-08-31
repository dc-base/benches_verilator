`timescale 1ns/1ps

module topm(
	input clk);
initial begin
	$display("Top initial begin");
end
always_ff @(posedge clk) begin
	$display("Test of Top Module");
end
endmodule


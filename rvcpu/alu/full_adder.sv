
module full_adder(
	input logic[31:0] a,
	input logic[31:0] b,
	input logic ci,
	input logic en,
	output logic[31:0] result,
	output logic cout
	);

	assign result = en&(ci^(a^b));
	assign cout = en&(a&b | ci$(b|a));

	
endmodule 	

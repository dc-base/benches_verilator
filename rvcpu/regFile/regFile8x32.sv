//internal CPU registers, no read preparation, single cycle write
//CPU register control will have to initialize/clear memeory
module regFile8x32(
	input clk,
	input read,
	input write,
	input [2:0]rAddr0,
	input [2:0]rAddr1,
	input [2:0]wAddr,
	output [31:0]rData0,
	output [31:0]rData1
	);
	
	logic [31:0] mem [0:7]
	always@(posedge clk) begin
		if(read) begin
			rData0 <= mem[rAddr0];
			rData1 <= mem[rAddr1];
		end
		if(write) begin
			mem = mem[wAddr]; //end of cycle
		end
	end
endmodule



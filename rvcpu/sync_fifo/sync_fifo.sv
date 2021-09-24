//basic sync_fifo as the baseline for the scheduling queue and ROB
module sync_fifo(
	input clk,
	input rst,
	input write,
	input read,
	input [31:0]wrData,
	output [31:0]rdData,
	output empty,
	output full
	);
	
	logic [31:0] mem [0:7];
	byte w_ptr;
	byte r_ptr;

	byte count;
	assign full = count == 8;
	assign empty = count == 0;
	always@(posedge clk or negedge rst) begin
		if(~rst) begin
			r_ptr <= 0;
		end
		else if (read && ~empty) begin
			rdData <= mem[r_ptr];
			if(r_ptr == 0

	end
	
	always@(posedge clk or negedge rst) begin
		if(~rst) begin

	
	always@(posedge clk or negedge rst) begin
		if(~rst) begin
			count <= 0;
		end
		else if(read && !write && count != 0) begin
			count = count - 1;
		end
		else if(write && !read && count != 8) begin
			count = count + 1;
		end
	end 

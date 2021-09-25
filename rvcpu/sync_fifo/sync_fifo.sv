//basic sync_fifo as the baseline for the scheduling queue and ROB
module sync_fifo(
	input logic clk,
	input logic rst,
	input logic write,
	input logic read,
	input logic [31:0]wData,
	output logic [31:0]rdData,
	output logic empty,
	output logic full
	);
	
	bind sync_fifo asserts_sync_fifo test(clk, rst, write, read, wData, rdData, empty, full);

	logic [31:0] mem [0:7];

	logic [2:0]w_ptr;
	logic [2:0]r_ptr;

	byte count;
	assign full = count == 8;
	assign empty = count == 0;
	//Read block
	always@(posedge clk or negedge rst) begin
		if(~rst) begin
			r_ptr <= 0;
		end
		else if (read && ~empty) begin
			rdData <= mem[r_ptr];
			if(r_ptr == 7) begin
				r_ptr <= 0;
			end
			else begin
				r_ptr <= r_ptr + 1;
			end
		end 
	end
	//Write block
	always@(posedge clk or negedge rst) begin
		if(~rst) begin
			w_ptr <= 0;
		end
		else if (write && ~full) begin
			mem[w_ptr] <= wData;
			if(w_ptr == 7 && ~full) begin
				w_ptr <= 0;
			end
			else begin
				w_ptr <= w_ptr + 1;
			end 
		end
	end
	//Fifo elements counter
	always@(posedge clk or negedge rst) begin
		if(~rst) begin
			count <= 0;
		end
		else if(read && !write && count != 0) begin
			count <= count - 1;
		end
		else if(write && !read && count != 8) begin
			count <= count + 1;
		end
	end 
endmodule 

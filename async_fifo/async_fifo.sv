`timescale 1ns/1ps

module async_fifo
	#(parameter PNTR_WIDTH = 8,
		parameter DATA_WIDTH = 8,
		parameter FIFO_DEPTH = 8) 
		
	(
	//w_clk,
	//r_clk,
	//re,
	//we,
	//rst,
	//din,
	//dout,
	//full,
	//empty
	fifo_if mif
);

//parameter PNTR_WIDTH = 8;
//parameter FIFO_DEPTH = 8;
//parameter DATA_WIDTH = 8;

//input logic w_clk, r_clk, we, re, rst;
//input logic [DATA_WIDTH-1:0] din;
//output logic [DATA_WIDTH - 1:0] dout; //Data in Data out declarations based on params
//output logic full, empty;

logic [PNTR_WIDTH - 1:0] w_ptr, r_ptr; //Internal pointers

logic [DATA_WIDTH - 1:0] mem [FIFO_DEPTH - 1:0]; //2D memory array

//logic [PNTR_WIDTH- 1:0] rw_diff; //interal staus indicator for verif

assign mif.full = w_ptr == FIFO_DEPTH - 1; //Full when w_ptr = max fifo size

assign mif.empty = w_ptr == 0; //Empty when w_pntr at bottom of array

//always_ff@(negedge rst) begin
//	if(~rst) begin
//		w_ptr <= 0;
//		r_ptr <= 0;
//		end
//	end
//Write block
always@(posedge mif.w_clk or posedge mif.r_clk) begin
	if(mif.w_clk) begin
		$display("Write clocked");
	end
	if(mif.r_clk) begin
		$display("Read clocked");
	end
end 
always_ff@(posedge mif.w_clk or negedge mif.rst) begin
	if(~mif.rst) begin
		w_ptr <= 0;
	end
	else if(mif.we && !mif.full) begin
		mem[w_ptr] <= mif.din; //Blocking to make sure ptr does not decrement
		w_ptr <= w_ptr + 1; 
		end
	end
//Read block
always_ff@(posedge mif.r_clk or negedge mif.rst) begin
	if(~mif.rst) begin
		r_ptr <= 0;
	end
	else if(mif.re && !mif.empty) begin
		mif.dout <= mem[r_ptr];
		r_ptr <= r_ptr - r_ptr;
		end
	end

//always_comb begin
//	rw_diff = w_ptr - r_ptr;
//	end

endmodule


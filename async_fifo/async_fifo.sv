`timescale 1ns/1ps

module async_fifo(
	input w_clk,
	input r_clk,
	input re,
	input we,
	input rst,
	input din,
	output dout,
	output full,
	output empty
);

parameter PNTR_WIDTH = 8;
parameter FIFO_DEPTH = 8;
parameter DATA_WIDTH = 8;

logic [0:DATA_WIDTH-1] din, dout; //Data in Data out declarations based on params

logic [0:FIFO_DEPTH - 1] w_ptr, r_ptr; //Internal pointers

logic [0:DATA_WIDTH - 1] mem [FIFO_DEPTH - 1:0]; //2D memory array

logic [0:FIFO_DEPTH - 1] rw_diff; //interal staus indicator for verif

assign full = w_ptr == FIFO_DEPTH - 1; //Full when w_ptr = max fifo size

assign empty = w_ptr == 0; //Empty when w_pntr at bottom of array

always_ff@(negedge rst) begin
	w_ptr <= 0;
	r_ptr <= 0;
	end
//Write block
always_ff@(posedge w_clk) begin
	if(~rst) begin
	end
	else if(we && !full) begin
		mem[w_ptr] <= din; //Blocking to make sure ptr does not decrement
		w_ptr <= w_ptr + 1; 
		end
	end
//Read block
always_ff@(posedge r_clk) begin
	if(~rst) begin
	end
	else if(re && !empty) begin
		dout <= mem[r_ptr];
		r_ptr <= r_ptr - r_ptr;
		end
	end

always_comb
	rw_status = w_ptr - r_ptr;
	end

endmodule


`timescale 1ns/1ps

module ddr_ctrl(
	input clk_n, 
	input clk_p,
	input we,
	input re,
	input rst,
	inout [63:0] DQ,
	inout DQS,
	input [31:0] addr
);

struct {
	bit[0:1] mode;
	bit[31:0] address;
}buffer_item;

logic[0:1] state;
logic[0:1] next;
enum {RESET, BOOT, READ, READ_2, WRITE, WRITE_2} mode;

always_ff@(posedge clk or negedge rst) begin
	if(~rst) begin
		state <= RESET;
	end
	else begin
		state <= next;
	end
end 

buffer_item buffer[$]
always@(posedge clk) begin
	case (state) begin
		RESET: begin
		end
		BOOT: begin
		end
		READ: begin
		end
		READ_2: begin
		end
		WRITE: begin
		end
		WRITE_2: begin
		end
		default: begin
		end
	endcase
end
//Load Queue every cycle
always@(posedge clk) begin
	if(we) begin
		buffer.push_back({1, we, addr});
	end
	else if(re) begin
		buffer.push_back({0, re, addr});
	end
end


endmodule





//assertion bind file to ensure fifo behavior
/* verilator lint_off UNUSED */
module asserts_sync_fifo(
	input logic clk,
	input logic rst,
	input logic write,
	input logic read,
	input logic [31:0]wData,
	input logic [31:0]rdData,
	input logic empty,
	input logic full
	);
	initial begin
		$display("hello from binded assertion module");
	end
	
	//property flags;
	//	@(posedge clk) disable iff (~rst)	
	//		!(empty == full);
	//endproperty
	//prop_status_flags: assert property(flags)
	//	else $display([SVA] full and empty fail);
	
	propEmptyFullFlags: assert property (@(posedge clk)!(empty == full)) else begin
		//$error("[SVA] full and empty fail"); //error will abort sim
		$display("[SVA] full and empty fail, Full: %b Empty: %b", full, empty);
	end

	always@(posedge clk) begin
		$display("COUNT: %d", sync_fifo.count);
	end

endmodule
/* verilator lint_on UNUSED */


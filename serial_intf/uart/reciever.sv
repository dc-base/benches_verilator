

module reciever(
	input logic rx,
	);
	
	integer counter;
	
	typedef enum{IDLE, COUNT} state;
	initial begin
		counter = 0;
		state = state.IDLE;
	end
	
	always@(posedge clk) begin

	end
endmodule
		

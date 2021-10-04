
module multiplier_loop(
	input logic clk, 
	input logic[15:0] a,
	input logic[15:0] b,
	input logic start_flag,
	output logic done_flag,
	output signed logic[31:0] result
	);
	
	typedef enum{IDLE, SIGNS, START, DONE} state;
	//bit[2:0] state;
	logic[15:0] M, Q, local_A;
	logic[32:0] organizer; //32bit + c0
	logic sign_status;
	logic c0;
	initial begin
		state = IDLE; //No reset dependency
	end

	function checkSign;
		if(M[15] && Q[15]) begin
			M = ~M + 1;
			Q = ~Q + 1;
			sign_status = 0;
		end
		else if(M[15] && !Q[15]) begin
			M = ~M + 1;
			sign_status = 1;
		end
		else if(!M[15] && Q[15] begin
			Q = ~Q + 1;
			sign_status = 1;
		end
		else begin
			sign_status = 0;
		end
		
	end
	always@(posedge clk) begin
		if(start_flag && (state == state.IDLE || state == state.DONE)) begin
			M = a;
			Q = b;
			local_A = 0;
			c0 = 0;
			state = state.START;
		end
		else if(state == state.START) begin
			for(int i = 0; i < 15; i++) begin
				if({Q[0], c0} == 2'b01) begin
					local_A <= local_A + M
				end
				else if({Q[0], c0} == 2'b10) begin
					local_A <= local_A - M;
				end
				else begin
					$error("Fatal C1C0 error");
				end
				organizer <= {local_A, Q, c0} >> 1;
			        local_A <= organizer[32:17];
				Q <= organizer[16:1];
				c0 = organizer[0];
			end
			state <= state.DONE;
		end
		else begin
			state = state.DONE;
		end
	end
	assign result = (state == state.DONE)&(organizer[32:1]);
endmodule




module multiplier(
	input logic clk,
	input logic rst,
	input logic start_flag,
	input logic[15:0] a,
	input logic[15:0] b,
	output logic[31:0] result,
	output logic status
	);

	logic[15:0] M;
	logic[15:0] Q;
	logic[15:0] regA;
	logic c0;
	localparam n = 16;
	//localparam IDLE = 0;
	//localparam START = 1;
	//localparam CHECK = 2;
	//localparam COUNT = 3;
	//localparam SHIFT = 4;
	typedef enum{IDLE, CHECK, COUNT, SHIFT, DONE} status;
	byte counter;
	status state;
	status next_state;
	logic sign;
	//logic[2:0] state;
	//logic[2:0] next_state;
	logic[32:0] organizer;
	always@(posedge clk or negedge rst) begin
		if(~rst) begin
			state = IDLE;
			next_state = IDLE;
		end
		else begin
			state = next_state;
		end
	end
	
	always_comb begin
		case(state) begin
			IDLE: begin
				if(start_flag) begin
					count = 16;
					next_state = START;
					M = a;
					Q = b;
					regA = 0;
				end
			end
			START: begin
				if(M[0] == 1 && Q[0] == 1) begin
					M = ~M + 1;
					Q = ~Q + 1;
					sign = 0;
				end
				else if(M[0] == 1 && Q[0] != 1) begin
					M = ~M + 1;
					sign = 1;
				end
				else if(M[0] != 1 && Q[0] == 1) begin
					Q = ~Q + 1;
					sign = 1;
				end
				else begin
					sign = 0;
				end
				next_state = CHECK;
				
			end
			CHECK: begin
				if({Q[15],c0} == 2'b10) begin
					$display("sub\n");
					regA = regA - M;
				end
				else if({Q[15], c0} == 2'b01) begin
					$display("add\n");
					regA = A + M;
				end
				else begin
					$display("Failure at CHECK");
				end
				next_state = SHIFT;
				organizer = {
			end
			SHIFT: begin
				organizer = {A, Q, c0i} >> 1;
				count = count - 1;
				next_state = COUNT_CHECK;
			end
			COUNT_CHECK: begin
				if(!count) begin
					next_state = IDLE;
					result = organizer[32:1]; 
					status = 1;
				end
			end
			default: begin 
				next_state <= IDLE;
			end
		endcase



	end	

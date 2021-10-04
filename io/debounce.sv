
module debounce(
	input logic clk,
	input logic button,
	output logic debounced
	);

	typedef enum{IDLE, ACTIVE, DOWN}status;
	integer counter;
	localparam clockspeed = 50000000;
	localparam delayTime = clockspeed/100000;
	initial begin
		counter = 0;
	end
	always@(posedge clk) begin
		if(status == status.IDLE) begin
			if(button) begin
				status = status.DOWN;
			end
		end
		else if((status == status.DOWN)&&(!
	end

	always@(posedge clk) begin
		if(status == status.DOWN) begin
			if(counter >= delayTime) begin
				counter = 0;
			end
			else begin
		end



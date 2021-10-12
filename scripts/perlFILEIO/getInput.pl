#!/bin/perl

sub checkEven{
	while(true){
		print "Put: ";
	
		$num = <>;
	
		if($num % 2 == 0){
			print "number is even \n";
		}
		else{
			print "number is odd \n";
		}
	}
}
&checkEven();

exit 0;

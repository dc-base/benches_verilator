#!/bin/perl




open(F, ">dump.log") or die "Fail";

for(my $i = 0; $i < 20; $i++){
	print F "hello\n";
}
print F "[BYE]";

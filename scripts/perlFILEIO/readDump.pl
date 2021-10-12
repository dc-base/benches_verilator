#!/bin/perl
$passArg = $ARGV[0];

sub Find{
	my $findTerm = $_[0];
	print "searching for $findTerm";
	open(F, "<dump.log") or die "Failed to open";
	
	while(<F>){
		$line = $_;
		#print $line;
		
		if(index($line, $findTerm) != -1){
			print "found";
		}
	}

	my $priv = sub {
		print "PRIV";
	};
	#return(&$priv);		
}

Find($passArg);


exit 0

package Basic;

sub new{
	my $class = shift;
	my $self = { 'time' => shift
	};

	bless $self, $class; #bind
	return $self;
};



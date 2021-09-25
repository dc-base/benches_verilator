#!/usr/bin/perl

print __FILE__ . "\n";
print __PACKAGE__ . "\n";
#perl arrays can include whatever type
@arr = ("test", 2);

$size = @arr;
print "size: $size\n";
print "$arr[0]\n";
print "$arr[1]\n";

%table = ('uvm_test', "test.sv", 'uvm_sequence', "seq.sv", 'uvm_driver', "drv.sv");

print "$table{'uvm_test'}\n";
print "$table{'uvm_driver'}\n";

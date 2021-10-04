#!/usr/bin/perl


print "\n\nHello Test\n\n\n";

@arr = (1..100);
$brands = "Omega!Tissot!Seiko";
print scalar @arr, "\n";
$len = @arr;
print $len, "\n";

@brands = split("!", $brands);
print @brands;

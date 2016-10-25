use strict;
use warnings;

chomp (my $nameNumber = <>);
for (0 .. $nameNumber-1){
	chomp (my $name = <>);
	print ($name =~ m/^[_\.][0-9]+[a-zA-Z]*_?$/ ? "VALID\n" : "INVALID\n");
}
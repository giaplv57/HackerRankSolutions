use strict;
use warnings;

chomp (my $lineNumber = <>);
for (0 .. $lineNumber-1){
	chomp (my $line = <>);
	while ($line =~ m/<a.*?href="(.*?)".*?>([^<>]*?)<\/\w>/ig){
		print "$1," . $2=~ s/^\s+|\s+$//gr . "\n";
	}
}
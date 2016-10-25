use strict;
use warnings;

chomp (my $sentenceNumber = <>);
my @allLines = ();
for (0 .. $sentenceNumber-1){
	chomp (my $line = <>);
	push @allLines, $line;
}
chomp (my $queryNumber = <>);
for (0 .. $queryNumber-1){
	my $totalAppearTime = 0;
	chomp (my $subString = <>);
	foreach my $line (@allLines){
		my @matchArray = $line =~ /\w$subString\w/g;
		my $appearTime = @matchArray;
		$totalAppearTime += $appearTime;
	}
	print $totalAppearTime . "\n";
}
use strict;
use warnings;

chomp (my $sentenceNumber = <>);
my @allWord = ();
for (0 .. $sentenceNumber-1){
	chomp (my $sentence = <>);
	my @worldInSentence = split /[^\w]+/, $sentence;
	push @allWord, @worldInSentence; 
}
chomp (my $queryNumber = <>);
for (0 .. $queryNumber-1){
	chomp (my $query = <>);
	my $appearTime = 0;
	foreach (@allWord) { $appearTime++ if ($query eq $_); };
	print $appearTime . "\n";
}
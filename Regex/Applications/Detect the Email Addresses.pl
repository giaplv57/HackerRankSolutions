use strict;
use warnings;
use Set::Scalar;

chomp (my $lineNumber = <>);
my $allEmail = Set::Scalar->new;
for (0 .. $lineNumber-1){
	my $line = <>;
	while ($line =~ /([^\s]*?)@(.*?)\.([\w\.]*?)(?:\s|\.\s|!)/g){
		$allEmail->insert($1."@".$2.".".$3) if ($1 ne "" && $2 ne "" && $3 ne "");
	}
}
print join ";", sort @{ $allEmail };
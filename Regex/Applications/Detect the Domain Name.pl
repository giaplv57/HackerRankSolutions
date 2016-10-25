use strict;
use warnings;
use Set::Scalar;

chomp (my $lineNumber = <>);
my $allDomain = Set::Scalar->new;

for (0 .. $lineNumber-1){
	chomp (my $line = <>);
	$allDomain->insert($1.".".$2) while $line =~ /(?:(?:http:\/\/)|(?:https:\/\/))(?:www\.|ww2\.)?([\w\.-]*?)\.([\w\.-]*?)[\/?"\\_\s]/g;
}
print join ";", sort @{ $allDomain };
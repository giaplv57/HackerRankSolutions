use strict;
use warnings;
use Set::Scalar;

my $tagSet = Set::Scalar->new;
chomp (my $lineNumber = <>);
for (0 .. $lineNumber-1) {
	chomp (my $line = <>);
	my @matchTags = $line =~ m/<(?: ?)(\w*?)[( ?)>]/g;
	foreach my $tag (@matchTags){
		$tagSet->insert($tag);
	}
}
print  join ";", sort @{ $tagSet };

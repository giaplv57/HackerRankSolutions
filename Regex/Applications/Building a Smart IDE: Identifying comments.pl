use strict;
use warnings;

my $content = "";
foreach my $line ( <> ){
	$content .= $line;
}
my @allComment = $content =~ /(?|(\/\*(?:.*?)\*\/)|(\/\/(?:.*?))\n)/gs;
print join "\n", map {$_ = s/\n\s*/\n/rg} @allComment;

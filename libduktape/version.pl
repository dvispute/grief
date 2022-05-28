#!/usr/bin/perl -w
# -*- mode: perl; -*-
# $Id: version.pl,v 1.1 2022/05/26 13:00:12 cvsuser Exp $
# duktape version
#
# Copyright Adam Young 2022
# All rights reserved.
#
# The applications are free software: you can redistribute it
# and/or modify it under the terms of the GRIEF license.
#
# Redistributions of source code must retain the above copyright
# notice, and must be distributed with the license document above.
#
# Redistributions in binary form must reproduce the above copyright
# notice, and must include the license document above in
# the documentation and/or other materials provided with the
# distribution.
#
# The applications are distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
# ==end==
#

use strict;
use warnings 'all';
use Getopt::Long;
use POSIX qw(strftime asctime);

my $output  = "version.h";
my $prefix  = "DUKTAPE_";
my $version = "0.0.1";
my $builddate = undef;
my $help    = 0;

Usage() if (0 == GetOptions(
		'output=s'      => \$output,
		'prefix=s'      => \$prefix,
		'version=s'     => \$version,
		'date=i'        => \$builddate,
		'help'          => \$help)
			|| $help);

$version = "0.0.1"
	if (! $version);

$builddate = strftime('%Y%m%d', localtime)
	if (! $builddate);

Generate();

sub
Generate	#()
{
	open(FILE, ">${output}") or
		die "cannot create <${output}> : $!\n";

	my ($version1, $version2, $version3, $version4) =
		split(/\./, $version);

	my $timestamp = asctime(localtime);
	chomp($timestamp);

	$version2 = 0 if (! $version2);
	$version3 = 0 if (! $version3);

	print FILE <<"EOT";
// Auto-generated by Makefile ${timestamp}
#define ${prefix}VERSION "${version}"
#define ${prefix}VER_MAJOR ${version1}
#define ${prefix}VER_MINOR ${version2}
#define ${prefix}VER_REVISION ${version3}
#define ${prefix}BUILD_DATE "${builddate}"
EOT
	close(FILE);
}


sub
Usage		# ([message])
{
	print "\nversion.pl @_\n\n" if (@_);
	print <<EOU;

Usage: perl version.pl [options]

Options:
    --version <version>     Package version.
    --prefix <prefix>       Identifier prefix (optional).
    --date <date>           Build date (optionaL).

EOU
	exit 3;
}

1;

#end


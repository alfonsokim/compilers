#! /bin/sh

[ -x dcc ] || { echo "Error: dcc not executable"; exit 1; }

DIR="samples"

LIST=
if [ "$#" = "0" ]; then
	LIST=`ls $DIR/*.out`
else
	for test in "$@"; do
		LIST="$LIST $DIR/$test.out"
	done
fi

for file in $LIST; do
	base=`echo $file | sed 's/\(.*\)\.out/\1/'`

	ext=''
	if [ -r $base.frag ]; then
		ext='frag'
	elif [ -r $base.decaf ]; then
		ext='decaf'
	else
		echo "Error: Input file for base: $base not found"
		continue
	fi

	tmp=${TMP:-"/tmp"}/check.tmp
	if [ -r $base.in ]; then
		sh run $base.$ext 1>$tmp 2>&1 < $base.in
	else
		sh run $base.$ext 1>$tmp 2>&1
	fi
        
	printf "Checking %-27s: " $file
	#if ! cmp -s $tmp $file; then
        if ! diff --ignore-all-space $tmp $file; then
		echo "FAIL <--"
		diff $tmp $file
	else
		echo "PASS"
	fi
done

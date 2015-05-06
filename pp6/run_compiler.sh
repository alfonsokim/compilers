#!/bin/bash
FILES=samples/*.decaf
for f in $FILES
do
  filename=$(basename "$f")
  filename="${filename%.*}"
  echo "Processing $filename file..."
  ./dcc < $f > results/optimized/${filename}.asm
done

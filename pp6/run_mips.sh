#!/bin/bash

FILES=results/optimized/*.asm
for f in $FILES
do
  filename=$(basename "$f")
  filename="${filename%.*}"
  echo "Processing $filename file..."
  java -jar ~/Dropbox/MCC/Tesis/Mars4_5.jar sm nc ic $f > results/optimized/${filename}.results
done
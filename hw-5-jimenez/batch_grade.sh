#!/bin/bash
standard="17322a2cfd320a23266116c4c2c95b3feea3e57fa3d9dfe8b8591e1d72120f26c6fadb"
FILES=./tograde/*

echo "Standard running time:"
time result="$(./fib.old 400)"

for f in $FILES
do
  echo "==================================================================="
  echo "Processing $f directory..."
  # take action on each file. $f store current file name
  #cat $f
  cd $f
    echo "The standard results:"
    echo $standard

    gcc -O3 -o fib.new ../../fib.c *.S
    time result="$(./fib.new 400)"

    result="$(echo ${result} | cut -d' ' -f 800)"

    echo "The execution results:"
    echo $result

    echo "Comparing between the result and standard solution:"
    if [ "$result" = "$standard" ]; then
      echo "PASS"
    else
      echo "FAIL"
    fi;

  cd ../..
done

#!/bin/sh
#@course TAMU CSCE 312 Computer Organization
#@description Homework1 test automation
#@author Yukun Zeng

#grammar used to test correctness
#OUTPUT="$(./hex b d 1000)"
#echo $OUTPUT
#INPUT="binary 1000 is decimal 8"
#if [ "$OUTPUT" = "$INPUT" ]
#then
#  echo "PASS"
#else
#  echo "FAIL"
#fi

input="$1"
while IFS=: read -r var1 var2
do
    #echo "$var1"
    #echo "$var2"
    #output of the program
    OUT="$($var1)"
    #answer of the problem
    ANS="$var2"
    if [ "$OUT" = "$ANS" ]
    then
      echo "PASS"
    else
      echo "FAIL"
    fi
done < "$input"

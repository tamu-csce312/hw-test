#!/bin/bash
pass=0
input=$1
line=0
declare -A matrix
# get the input command and expected running result
while IFS=: read -r var1 var2
do
    #echo "Command: $var1"
    #echo "$var2"
    line=$((line+1))
    matrix[$line, 1]=$var1
    matrix[$line, 2]=$var2
done < "$input"
# compile and run all cpp files in current directory
for file in *.cpp
do
  pass=0
  rm -rf hex
  g++ $file -o hex
  echo "Running file "$file
  for ((i=1; i<=$line; i++))
  do
      var1=${matrix[$i, 1]}
      var2=${matrix[$i, 2]}
      #echo "Command: $var1"
      #output of the program
      OUT="$($var1)"
      #echo "OUTPUT: "$OUT
      #answer of the problem
      ANS="$var2"
      #echo "ANSWER: "$ANS
      if [ "$OUT" = "$ANS" ]
      then
        #echo "=====================PASS======================"
        pass=$((pass+1))
      #else
        #echo "=====================FAIL======================"
      fi
  done
  echo $file" Total Pass: $pass/$line"
done

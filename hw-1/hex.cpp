#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <functional>
#include <string.h> // in case you want to use e.g. memset
#include <math.h>
#include <string>
#include <bitset>

using namespace std;

// TODO how to deal with errors?
string decToBinStr(long input){
  int rem;
  if(input / 2 != 0){
    return (decToBinStr(input / 2) + to_string(input % 2));
  }
  return (to_string(input));
}

long hexStrToDec(char *input, int strLen){
  long sum = 0;
  //cout << "input length: " << strLen << endl;
  for(int i = strLen - 1; i >= 0; i --){
    int digit = strLen - i - 1;
    if(input[i] >= 48 && input[i] <= 57){
      sum += (input[i] - 48) * pow(16, digit);
    }
    else if(input[i] >= 97 && input[i] <= 102){
      sum += (input[i] - 97 + 10) * pow(16, digit);
    }
    else
      return 0;
  }
  return sum;
}

long binStrToDec(char *input, int strLen){
  long sum = 0;
  for(int i = strLen - 1; i >= 0; i --){
    int digit = strLen - i - 1;
    if(input[i] == '0');
    else if(input[i] == '1')
      sum += pow(2, digit);
    else return 0;
  }
  return sum;
}

long strToDec(char *input, int strLen){
  long sum = 0;
  for(int i = strLen - 1; i >= 0; i --){
    int digit = strLen - i - 1;
    if(input[i] >= 48 && input[i] <= 57)
      sum += (input[i] - 48) * pow(10, digit);
    else return 0;
  }
  return sum;
}

int strLength(char* input){
  int i;
  for(i = 0; input[i] != '\0'; i ++);
  return i;
}

int main(int argc, char *argv[]){
  if(argc != 4){
    cout << "Usage: " << "Usage: ./hex [ h | d | b ] [ h | d | b]" << endl;
  }
  // input str length
  int length = strLength(argv[3]);
  // input decimal as a long variable
  long inputDec = 0;
  // output str
  string origin = "decimal", target = "decimal";
  // translate input str to long type
  switch (argv[1][0]){
    case 'h':
      inputDec = hexStrToDec(argv[3], length);
      origin = "hexadecimal ";
      break;
    case 'd':
      inputDec = strToDec(argv[3], length);
      origin = "decimal ";
      break;
    case 'b':
      inputDec = binStrToDec(argv[3], length);
      origin = "binary ";
      break;
    default:
      cout << "Usage: " << "Usage: ./hex [ h | d | b ] [ h | d | b]" << endl;
  }
  switch (argv[2][0]){
    case 'h':
      target = "hexadecimal ";
      cout << origin << argv[3] << " is " << target
        << hex << inputDec << endl;
      break;
    case 'd':
      target = "decimal ";
      cout << origin << argv[3] << " is " << target
        << inputDec << endl;
      break;
    case 'b':
      target = "binary ";
      cout << origin << argv[3] << " is " << target
        << decToBinStr(inputDec) << endl;
      break;
    default:
      cout << "Usage: " << "Usage: ./hex [ h | d | b ] [ h | d | b]" << endl;
  }
  //cout << origin << argv[3] << " is decimal " << inputDec << endl;
  //cout << hex << inputDec << endl;
  //cout << decToBinStr(inputDec) << endl;
}


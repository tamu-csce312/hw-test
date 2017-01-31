#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <functional>
#include <string.h> // in case you want to use e.g. memset
#include <math.h>

using namespace std;

long hexToDec(char *input, int strLen){
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

long binToDec(char *input, int strLen){

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
  int length = strLength(argv[3]);
  int dec = hexToDec(argv[3], length);
  cout << "hexadecimal " << argv[3] << " is decimal " << dec << endl;
}


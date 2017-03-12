#include <stdio.h>
/*
 * Write a C program to:
 * 1. read in two numbers (in hexadecimal)
 * 2. reverse the order of the bytes in the first number
 * 3. interleave the bytes of this new number with the bytes of the other input
 * 4. print out the result (in hex).
 * For example, input of 1234abcd and abcd1234 would give cdababcd and 34121234 as output
 * (cdab3412 is the reversed byte order of the first input). Since we are interleaving
 * two 32-bit values the result is a 64-bit value which I'm showing above as two
 * separate output values (unsigned ints). There are alternative methods that could
 * produce a single sequential output rather than two outputs. Either approach is
 * correct.

 * Your program must read a hex value into an unsigned int variable and use bit
 * operations on unsigned int variables.

 * Hint: You can use scanf("%x",&foo); to read a hex value into an unsigned integer
 * variable foo from standard input
 */

void main(){
  // read in two numbers (in hexadecimal)
  unsigned int number1, number2;

  printf("First Number: ");
  scanf("%x", &number1);

  printf("Second Number: ");
  scanf("%x", &number2);

  // reverse the order of the bytes in the first number
  unsigned int byte0 = (number1 & 0xFF000000) >> 6 * 4;
  unsigned int byte1 = (number1 & 0x00FF0000) >> 2 * 4;
  unsigned int byte2 = (number1 & 0x0000FF00) << 2 * 4;
  unsigned int byte3 = (number1 & 0x000000FF) << 6 * 4;
  number1 = byte0 | byte1 | byte2 | byte3;

  // interleave the bytes of this new number with the bytes of the other input
  unsigned int newNumber1 = (number1 & 0xFFFF0000) | (number2 & 0xFFFF0000) >> 4 * 4;
  unsigned int newNumber2 = (number2 & 0x0000FFFF) | (number1 & 0x0000FFFF) << 4 * 4;

  // print out the result (in hex)
  printf("%x\n", newNumber1);
  printf("%x\n", newNumber2);
}

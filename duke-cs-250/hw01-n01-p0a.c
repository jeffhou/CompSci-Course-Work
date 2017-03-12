#include <stdio.h>
/*
 * Compile with `gcc -o output-hw01-n01-p-0a hw01-n01-p0a.c`
 * Run after compiling with `./output-hw01-n01-p0a
 */

/*
 * Prints the two passed in parameters in two different ways: int and char representation.
 */
void print_ascii(char *c, int i){
  printf("Representations of char\n int: %d, char: %c\n", *c, *c);
  printf("Representations of int\n int: %d, char: %c\n", i, i);
}

void main(){
  // there are 32 ascii characters between lowercase and uppercase
  print_ascii("a", 'a' - 32); // same as print_ascii("a", 'A');
  // goes to the end of the alphabet
  print_ascii("a", 'a' + 25); // same as print_ascii("a", 'z');
  // views one of the symbols between lowercase and uppercase characters
  print_ascii("a", 'a' - 1); // same as print_ascii("a", '`');
  // representing integer for the character
  print_ascii("a", 115); // same as print_ascii("a", 's');
}

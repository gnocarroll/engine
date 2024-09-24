/*
 *  Converts uppercase letters from STDIN into lowercase letters before sending
 *  them to STDOUT.
 */

#include <stdio.h>

int main(void) {
  int c;

  while ((c = getchar()) != EOF) {
    if ((c >= 'A') && (c <= 'Z')) {
      putchar(c + ('a' - 'A'));
    }
    else {
      putchar(c);
    }
  }

  return 0;
}

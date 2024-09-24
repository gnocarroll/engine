/*
 *  Converts lowercase letters from STDIN into uppercase letters before sending
 *  them to STDOUT.
 */

#include <stdio.h>

int main(void) {
  int c;

  while ((c = getchar()) != EOF) {
    if ((c >= 'a') && (c <= 'z')) {
      putchar(c + ('A' - 'a'));
    }
    else {
      putchar(c);
    }
  }

  return 0;
}

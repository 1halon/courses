#include <stdio.h>

int main(void) {
  for (int i = 0; i < 256; i++) {
    printf("%d - %c\n", i, (char)i);
  }

  return 0;
}

#include <stdio.h>

int main(void) {
  while (1) {
    unsigned int x;
    unsigned int y = 1;

    printf("Input: ");
    scanf("%d", &x);
    if (!x)
      break;

    for (int i = 1; i <= x; i++) {
      y *= i;
    }

    printf("Output: %d\n", y);
  }

  return 0;
}

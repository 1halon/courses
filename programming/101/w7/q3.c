#include <stdio.h>

int main(void) {
  int x, y = 0;

  while (1) {
    printf("Input: ");
    scanf("%d", &x);
    if (!(x % 2))
      break;

    y += x;
  }

  printf("Output: %d\n", y);

  return 0;
}

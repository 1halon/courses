#include <stdio.h>

int main(void) {
  int x = 0;
  int y = 1;

  printf("Input: ");
  scanf("%d", &x);

  for (int i = 2; i * i <= x; i++) {
    if (!(x % i)) {
      if (i * i != x)
        y += i + x / i;
      else
        y += i;
    }
  }

  printf("\"%d\" is %sperfect\n", x, (y == x && x != 1) ? "" : "not ");

  return 0;
}

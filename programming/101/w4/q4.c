#include <stdio.h>

int main(void) {
  int x;
  int y;
  int z;

  printf("X: ");
  scanf("%d", &x);

  printf("Y: ");
  scanf("%d", &y);

  z = x * y;

  printf("x + y + z = %d + %d + %d = %d\n", x, y, z, x + y + z);

  return 0;
}

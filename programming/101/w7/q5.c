#include <stdio.h>

int main(void) {
  int x;

  printf("Input: ");
  scanf("%d", &x);

  int y = snprintf(NULL, 0, "%d", x);
  char z[sizeof(char) * (y + 1)];
  snprintf(z, sizeof(z), "%d", x);

  for (int i = 0; i < y / 2; i++) {
    int t = z[i];
    int w = y - i - 1;
    z[i] = z[w];
    z[w] = t;
  }

  printf("%s\n", z);

  return 0;
}

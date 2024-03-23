#include <stdio.h>
#include <stdlib.h>

int reverse(int *n) {
  int l = snprintf(NULL, 0, "%d", *n);
  char *b = malloc((l + 1) * sizeof(char));

  snprintf(b, sizeof(b), "%d", *n);

  for (int i = 0; i < l / 2; i++) {
    int t = b[i];
    int i2 = l - i - 1;
    b[i] = b[i2];
    b[i2] = t;
  }

  sscanf(b, "%d", n);
  free(b);

  return *n;
}

int main(void) {
  int x = 0;
  printf("Input: ");
  scanf("%d", &x);
  printf("Output: %d\n", reverse(&x));

  return 0;
}

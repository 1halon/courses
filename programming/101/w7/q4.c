#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *x = malloc(sizeof(int));
  if (x == NULL) {
    printf("Memory allocation failed.\n");
    return 139;
  }

  int y = 0;

  while (1) {
    int z;
    printf("Input: ");
    scanf("%d", &z);
    if (z == -1)
      break;

    x[y] = z;
    y++;
  }

  int z, w;
  for (int i = 0; i < y; i++) {
    int v = x[i];

    if (v > z)
      z = v;
    else if (v < w)
      w = v;
  }

  printf("Max: %d | Min: %d\n", z, w);

  free(x);

  return 0;
}

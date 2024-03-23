#include <stdio.h>
int main(void) {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int size = (sizeof arr / sizeof arr[0]);
  int acc = 0;
  for (int i = 0; i < size; i++)
    acc += arr[i];

  printf("Output: %d\n", acc / size);

  return 0;
}

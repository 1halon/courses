#include <stdio.h>

int main(void) {
  int no;
  int first;
  int second;
  int final;

  printf("No: ");
  scanf("%d", &no);

  printf("First: ");
  scanf("%d", &first);

  printf("Second: ");
  scanf("%d", &second);

  printf("Final: ");
  scanf("%d", &final);

  int note = (.25 * (first + second)) + (.5 * final);

  printf("\nNo: %d | Note: %d\n", no, note);

  return 0;
}

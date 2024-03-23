#include <stdio.h>
#include <string.h>

int main(void) {
  char username[9] = "username";
  char password[9] = "password";

  while (1) {
    char input[9];
    printf("Username: ");
    scanf("%s", input);
    if (strcmp(input, username))
      continue;

    int i = 0;
    while (1) {
      if (i == 3) {
        printf("ACCESS DENIED\n");
        return -1;
      }
      printf("Password: ");
      scanf("%s", input);
      if (strcmp(input, password)) {
        i++;
        continue;
      }

      printf("ACCESS GRANTED\n");

      return 0;
    }
  }
}

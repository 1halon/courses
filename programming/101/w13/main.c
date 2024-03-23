int main(void) {
  int x[3][2] = {{1, 2}, {3, 4}, {5, 6}};
  int y[3][2] = {{7, 8}, {9, 10}, {11, 12}};
  int z[3][2];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      z[i][j] = x[i][j] + y[i][j];
    }
  }

  return 0;
}

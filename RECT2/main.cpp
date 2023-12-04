#include <iostream>

using namespace std;

int x[5], y[5];

int main() {
  scanf("%d%d%d%d%d%d", &x[1], &y[1], &x[2], &y[2], &x[3], &y[3]);

  int x4 = x[1] ^ x[2] ^ x[3], y4 = y[1] ^ y[2] ^ y[3];

  printf("%d %d", x4, y4);

  return 0;
}
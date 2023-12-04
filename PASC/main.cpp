#include <cstdio>
#include <iostream>

using namespace std;

int n, a[55][55];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  a[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      if (j == i || j == 1) {
        a[i][j] = 1;
      } else {
        a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}
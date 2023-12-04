#include <iostream>

using namespace std;

int n, a[31];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;

  for (int i = 1; i <= n; i++)
    cin >> a[i];

  for (int i = 1; i <= n - 1; i++) {
    int key = a[i];
    int j = i - 1;
    bool flag = false;
    while (j >= 1 && a[j] > key) {
      a[j + 1] = a[j];
      j = j - 1;
      flag = true;
    }
    a[j + 1] = key;
    if (flag) {
      printf("%d %d\n", key, j);
    }
  }
  return 0;
}
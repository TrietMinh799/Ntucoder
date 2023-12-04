#include <cstdio>
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
    int min_idx = i;
    for (int j = i + 1; j <= n; j++) {
      if (a[j] < a[min_idx])
        min_idx = j;
    }
    if (min_idx != i) {
      swap(a[min_idx], a[i]);
    }
    for (int k = 1; k <= n; k++) {
      if (k == min_idx || k == i) {
        printf("[%d] ", a[k]);
      } else {
        printf("%d ", a[k]);
      }
    }
    printf("\n");
  }
}
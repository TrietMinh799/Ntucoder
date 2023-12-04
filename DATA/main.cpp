#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 11;
int n, a[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;

  for (int i = 1; i <= n; i++)
    cin >> a[i];

  vector<int> idx;
  for (int i = 1; i <= n; i++) {
    if (a[i] > a[i - 1]) {
      continue;
    } else {
      if (!idx.empty()) {
        printf("%d", -1);
        return 0;
      }
      idx.push_back(i);
    }
  }

  if (idx.empty())
    printf("%d", -1);
  else {
    printf("%d", (a[n] < a[1] ? idx[0] : -1));
  }

  return 0;
}
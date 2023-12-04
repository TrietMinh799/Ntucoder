#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 2e5 + 10;

int n, m;
pii a[MAXN];

bool cmp(const pii &a, const pii &b) { return a.first < b.first; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> a[++m].first;
    a[m].second = 0;
  }

  for (int i = 1; i <= n; i++) {
    cin >> a[++m].first;
    a[m].second = 1;
  }

  sort(a + 1, a + 1 + m, cmp);

  int now = a[1].second, res = 0;
  for (int i = 2; i <= m; i++) {
    if (a[i].second + now == 1) {
      ++res;
      now = -1;
    } else {
      now = a[i].second;
    }
  }

  printf("%d", res);

  return 0;
}

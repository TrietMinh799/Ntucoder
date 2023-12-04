#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

const int MAXSIZE = 1e5 + 10;

int t, n, k, p, a[MAXSIZE];

void solve() {
  cin >> n >> k >> p;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);

  for (int i = 0; i < n; i++) {
    ll curr = a[i] + (2 * p);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;

  while (t--)
    solve();

  return 0;
}
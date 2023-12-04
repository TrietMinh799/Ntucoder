#include <iostream>
#include <vector>

using namespace std;

int f[4][1010][1010], ans = 0, n, m, a[1010][1010];

int solve(int dir, int i, int j) {
  if (a[i][j] == 0)
    return 0;
  if (i > n || i <= 0 || j > m || j <= 0)
    return 0;
  if (f[dir][i][j] != -1)
    return f[dir][i][j];

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      for (int k = 0; k < 4; ++k)
        f[k][i][j] = -1;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == 0)
        continue;
        int sum = solve(0,)
    }
  }
  return 0;
}
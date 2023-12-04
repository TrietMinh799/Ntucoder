#include <iostream>

using namespace std;

int n, m, cnt, a[110][110], f[110][110], trace[110][110], res[11000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i <= m; i++)
    f[1][i] = a[1][i];

  for (int i = 2; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      for (int k = 0; k <= j; k++)
      {
        if (f[i - 1][k] + a[i][j - k] > f[i][j])
        {
          f[i][j] = f[i - 1][k] + a[i][j - k];
          trace[i][j] = k;
        }
      }
    }
  }

  int i = n, j = m;

  cout << f[n][m] << "\n";

  while (cnt != n - 1)
  {
    res[++cnt] = j - trace[i][j];
    m -= res[cnt];
    j = trace[i][j];
    i--;
  }
  res[++cnt] = m;

  for (i = 1; i <= n; i++)
  {
    cout << res[cnt + 1 - i] << "\n";
  }

  return 0;
}

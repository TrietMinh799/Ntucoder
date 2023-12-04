#include <bits/stdc++.h>

using namespace std;

int a[100005], f[100005] = {0}, n, m;

void update(int m, int values)
{
    while (m <= n)
    {
        f[m] += values;
        m
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        a[i] = n - i + 1;
    }

    int q;
    for (int i = 1; i <= m; i++)
    {
        cin >> q;
    }

    return 0;
}

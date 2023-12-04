#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll u, v, n, m, a[100001], pf[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    pf[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pf[i] = pf[i - 1] + a[i];
    }

    while (m--)
    {
        cin >> u >> v;

        ll l = u, r = v, resMin = 1e18;
        ll sum = pf[v] - pf[u - 1];

        while (l <= r)
        {
            ll mid = (l + r) / 2;
            ll sumA = pf[mid] - pf[u - 1];
            ll sumB = sum - sumA;
            resMin = min(resMin, abs(sumA - sumB));
            if (sumB > sumA)
            {
                l = mid + 1;
            }
            else if (sumB < sumA)
            {
                r = mid - 1;
            }
            else
                break;
        }
        cout << resMin << "\n";
    }
}
#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

int n, m;
ll a[200005], b[200005], res = 0, j = 0;

ll bs(ll a[], ll l, ll r, ll x)
{
    ll ans = -1;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (a[mid] <= x)
            l = mid + 1;
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }

    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);

    for (int i = 0; i < m; i++)
    {
        if (j == n)
            break;
        ll t = bs(a, j, n - 1, b[i]);
        if (t != -1)
        {
            j = t + 1;
            res++;
        }
    }

    cout << res << endl;
    return 0;
}
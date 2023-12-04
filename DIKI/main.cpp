#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

ll n, m, a[100000];

ll bs(ll a[], ll i, ll x)
{
    ll l = i, r = n - 1;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (a[mid] == x)
            return a[mid];
        else if (a[mid] > x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        ll j = bs(a, i + 1, a[i] + m);
        if (j != -1)
        {
            cout << a[i] << " " << j << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
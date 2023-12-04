#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

ll n, m, a[100001], pf[100001], x;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    pf[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pf[i] = pf[i - 1] + a[i];
    }

    cin >> m;

    while (m--)
    {
        cin >> x;

        ll t = lower_bound(pf + 1, pf + 1 + n, x) - pf;

        cout << t << " ";
    }

    return 0;
}
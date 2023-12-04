#include <iostream>

#define ll long long

using namespace std;

ll n, m, p, t, b, a[100000], c[100000], res;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> p >> t >> b;

    for (int i = 0; i < m; i++)
        cin >> a[i];

    for (int i = 0; i < p; i++)
        cin >> c[i];

    for (int i = 0; i < p; i++)
    {
        ll t = lower_bound(c, c + p, a[i]) - c;
    }

    return 0;
}
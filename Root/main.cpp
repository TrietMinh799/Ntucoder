#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

int t;
ll x;

void solve()
{
    cin >> x;
    ll outside = 1, inside = x, d = 2;
    while (d * d <= inside)
    {
        if (inside % (d * d) == 0)
        {
            inside /= d * d;
            outside *= d;
        }
        else
        {
            d++;
        }
    }

    cout << outside << " " << inside << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;

    while (t--)
        solve();

    return 0;
}

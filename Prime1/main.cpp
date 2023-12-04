#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
ll l, r;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t--)
    {
        cin >> l >> r;
        vector<bool> isPrime(r - l + 1, true);
        for (ll i = 2; i * i <= r; i++)
        {
            for (ll j = max(i * i, (l + i - 1) / i * i); j <= r; j += i)
            {
                isPrime[j - l] = false;
            }
        }

        if (1 >= l)
            isPrime[1 - l] = false;
        for (ll x = l; x <= r; x++)
        {
            if (isPrime[x - l])
            {
                cout << x << "\n";
            }
        }

        cout << "\n";
    }

    cout.flush();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll w;
int c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> w >> c;

    vector<ll> coins;
    for (int i = 0; i <= c; ++i)
    {
        for (const int &x : {1000, 2000, 3000, 5000})
        {
            coins.push_back(x * (ll)pow(10, i));
        }
    }

    sort(coins.begin(), coins.end(), greater<ll>());

    for (int i = 0; i <= coins.size(); ++i)
    {
    }
    return 0;
}
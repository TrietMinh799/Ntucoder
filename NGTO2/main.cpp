#include <iostream>
#include <vector>

#define ll long long

#define MAXSIZE 10000005

using namespace std;

ll n;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    vector<ll> cnt(MAXSIZE, true), nt;
    cnt[0] = cnt[1] = false;

    for (ll i = 2; i * i <= MAXSIZE; i++)
        if (cnt[i])
            for (ll j = i * i; j <= MAXSIZE; j += i)
                cnt[j] = false;

    nt.push_back(2);
    for (ll i = 3; i <= MAXSIZE; i++)
        if (cnt[i])
            nt.push_back(i);

    cout << nt[n - 1] << endl;

    return 0;
}
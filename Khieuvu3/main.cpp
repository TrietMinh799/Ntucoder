#pragma GCC optimize("O2")

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define ll long long

using namespace std;

int res = 0;
ll n, k;

int bs(vector<ll> a, ll low, ll high, ll x)
{
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;

    vector<ll> a(n);
    map<ll, ll> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        if (mp[a[i] + k] == 1)
            res++;
    }

    cout << res << endl;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

long long n, maxlength = 0, k, a[100005], sum = 0;
map<long long, long long> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++) {
        sum += a[i];
        int mod = sum % k;

        if(mod == 0)
            maxlength = i + 1;
        else if(mp.find(mod) == mp.end())
            mp[mod] = i;
        else
            maxlength = max(maxlength, i - mp[mod]);
    }

    cout << maxlength;

    return 0;
}

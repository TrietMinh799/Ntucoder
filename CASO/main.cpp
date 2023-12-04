#include <bits/stdc++.h>

using namespace std;

long long n, a[200005], ans = 0;
map<long long, long long> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    for(auto &itr : mp) {
        if(itr.second >= 2) {
            ans += (itr.second * (itr.second - 1)) / 2;
        }
    }

    cout << ans;

    return 0;
}

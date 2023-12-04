#include <bits/stdc++.h>

#define ll unsigned long long

using namespace std;

int n;
ll x;
pair<int, ll> a[100005];

bool cmp(pair<int, ll> a, pair<int, ll> b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }

    return a.first > b.first;
}

int ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x >> n;

    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    sort(a, a + n, cmp);

    for(int i = 0; i < n; i++) {
        ll nums = pow(10, a[i].first);
        if(x >= nums) {
            if(x >= nums * a[i].second) {
                x -= nums * a[i].second;
            } else {
                x -= ((ll)(x / nums)) * nums;
            }
            ans++;
        }

        if(x <= 0) break;
    }

    if(x > 0) {
        cout << -1;
    } else {
        cout << ans;
    }

    return 0;
}

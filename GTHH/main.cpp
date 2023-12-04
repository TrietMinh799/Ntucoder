#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 11;
int n;
ll a[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<ll> b;
    for(int i = 1; i <= n; i++) {
        if(i & 1) {
            b.push_back(1);
        } else {
            b.push_back(a[i]);
        }
    }
    ll sum = 0;
    for(int i = 1; i < n; i++) {
        sum += abs(b[i] - b[i - 1]);
    }

    printf("%lld", sum);
    return 0;
}

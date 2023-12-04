#include <bits/stdc++.h>

using namespace std;

typedef long double lb;
typedef long long ll;
typedef pair<ll, ll> pll;

int n, t;
pll a[100005];
vector<lb> elements;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> t;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        elements.push_back(a[i].first / a[i].second);
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll u, v, w[50], val[50], f[18][1 << 18];

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

ll query(int r, int l) {
    int t = log2_floor(r - l + 1);
    ll maximum = max(f[t][l], f[t][r - (1 << t) + 1]);
    return maximum;
}

void build(vector<pair<ll, ll>>& y) {
    for(int i = 0; i < y.size(); i++) {
        f[0][i] = y[i].second;
    }

    for(int i = 1; i < 18; i++) {
        for(int j = 0; j + (1 << i) <= y.size(); j++) {
            f[i][j] = max(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
        }
    }
}

void Try(int i, int des, ll values, ll weight, vector<pair<ll, ll>>& res) {
    if(i == des + 1) {
        res.emplace_back(make_pair(weight, values));
        return;
    }

    Try(i + 1, des, values, weight, res);
    if(w[i] + weight <= v) {
        Try(i + 1, des, values + val[i], weight + w[i], res);
    }
}

bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b) {
   return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> u >> v;

    for(int i = 1; i <= n; i++) {
        cin >> w[i] >> val[i];
    }

    vector<pair<ll, ll>> x, y;
    Try(1, n / 2, 0, 0, x);
    Try(n / 2 + 1, n, 0, 0, y);

    sort(x.begin(), x.end(), cmp);
    build(x);
    ll res = 0;
    for(auto &pll : y){
        int low = lower_bound(x.begin(), x.end(), make_pair((ll)u - pll.first, (ll) 0), cmp) - x.begin();
        int high = --upper_bound(x.begin(), x.end(), make_pair((ll)v - pll.first, (ll) 0), cmp) - x.begin();

        if(low < x.size() && high >= 0) {
            //cout << low << " " << high << "\n";
            res = max(res, pll.second + query(high, low));
        }
    }

    cout << (ll) res;

    return 0;
}

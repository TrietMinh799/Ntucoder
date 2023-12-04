#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

struct Node {
    long long val = 0;
    int cnt = 0;

    Node operator+(const Node& b) {
        Node res;
        res.val = val + b.val;
        res.cnt = cnt + b.cnt;
        return res;
    }
};

long long ans = 0;
const long long mod = 1e9;
long long n, a[MAXN], f[MAXN];
Node t[MAXN * 4], nulls;

void update(int v, int tl, int tr, int pos, long long val) {
    if(tl == tr) {
        t[v].val += val;
        t[v].cnt++;
        return;
    }

    int tm = tl + (tr - tl) / 2;
    if(pos <= tm) {
        update(v * 2, tl, tm, pos, val);
    } else {
        update(v * 2 + 1, tm + 1, tr, pos, val);
    }

    t[v] = t[v * 2] + t[v * 2 + 1];
}


Node query(int v, int tl, int tr, int l, int r) {
    if(l > r) {
        return nulls;
    }

    if(l == tl && r == tr) {
        return t[v];
    }

    int tm = tl + (tr - tl) / 2;
    return query(v * 2, tl, tm, l, min(tm, r)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        f[i] = a[i];
    }

    sort(a, a + n);

    for(int i = 0; i < n; i++) {
        f[i] = lower_bound(a, a + n, f[i]) - a;
    }

    for(int i = 0; i < n; i++) {
        Node node = query(1, 0, n - 1, f[i] + 1, n - 1);

        ans += abs(node.cnt * a[f[i]] - node.val);
        update(1, 0, n - 1, f[i], a[f[i]]);
    }

    cout << ans % mod;

    return 0;
}

#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

int n, q, a[MAXN], t[4 * MAXN];

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if(l > r)
        return 1e9;

    if(tl == l && tr == r) {
        return t[v];
    }

    int tm = (tl + tr) / 2;

    return min(query(2 * v, tl, tm, l, min(r, tm)),
               query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    build(1, 0, n - 1);

    while(q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        cout << query(1, 0, n - 1, l, r) << "\n";
    }

    return 0;
}

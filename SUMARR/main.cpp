#include <bits/stdc++.h>

#define MAXSIZE 1000005

using namespace std;

int q, n;
long long a[MAXSIZE], t[4 * MAXSIZE];

void build(int v, int tl, int tr)
{
    if(tl == tr)
    {
        t[v] = a[tl];
        return;
    }

    int tm = tl + (tr - tl) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);

    t[v] = t[v * 2] + t[v * 2 + 1];
}

void downto(int v, int tl, int tr, int pos, long long val)
{
    if(tl == tr)
    {
        t[v] -= val;
        return;
    }

    int tm = tl + (tr - tl) / 2;
    if(pos <= tm)
    {
        downto(v * 2, tl, tm, pos, val);
    }
    else
    {
        downto(v * 2 + 1, tm + 1, tr, pos, val);
    }

    t[v] = t[v * 2] + t[v * 2 + 1];
}

void upto(int v, int tl, int tr, int pos, long long val)
{
    if(tl == tr)
    {
        t[v] += val;
        return;
    }

    int tm = tl + (tr - tl) / 2;
    if(pos <= tm)
    {
        upto(v * 2, tl, tm, pos, val);
    }
    else
    {
        upto(v * 2 + 1, tm + 1, tr, pos, val);
    }

    t[v] = t[v * 2] + t[v * 2 + 1];
}

long long query(int v, int tl, int tr, int l, int r)
{
    if(l > r) return 0;

    if(l == tl && r == tr)
    {
        return t[v];
    }

    int tm = tl + (tr - tl) / 2;
    return query(v * 2, tl, tm, l, min(tm, r)) + query(v * 2 + 1,
            tm + 1, tr, max(tm + 1, l), r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    build(1, 0, n - 1);

    char types;
    int u, v;

    while(q--)
    {
        cin >> types >> u >> v;
        if(types == 'S')
        {
            cout << query(1, 0, n - 1, u, v) << "\n";
        } else if(types == 'U') {
            upto(1, 0, n - 1, u, v);
        } else {
            downto(1, 0, n - 1, u, v);
        }
    }

    return 0;
}

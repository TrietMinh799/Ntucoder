#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 11;

struct Node
{
    int optimal, open, close;
    Node()
    {
    }
    Node(int optimal, int open, int close)
        :optimal(optimal), open(open), close(close)
    {

    }


};
Node operator + (const Node& left, const Node& right)
{
    Node res;
    int tmp = min(left.open, right.close);
    res.optimal = left.optimal + right.optimal + tmp * 2;
    res.open = left.open + right.open - tmp;
    res.close = left.close + right.close - tmp;
    return res;
}
int n, q, l, r;
string s;
Node st[4 * MAXN];

void build(int id, int l, int r)
{
    if (l == r)
    {
        if (s[l] == '(') st[id] = Node(0, 1, 0);
        else st[id] = Node(0, 0, 1);
        return ;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid+1, r);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

Node query(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return Node(0, 0, 0);
    }
    if (u <= l && r <= v)
    {
        return st[id];
    }

    int mid = (l + r) / 2;
    return query(id * 2, l, mid, u, v) + query(id * 2 + 1, mid+1, r, u, v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    cin >> q;

    build(1, 0, n - 1);

    while(q--)
    {
        cin >> l >> r;

        Node ans = query(1, 0, n - 1, --l, --r);
        cout << ans.optimal << "\n";
    }

    return 0;
}

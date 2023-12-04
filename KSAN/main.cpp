#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, res = 0;
ll t[100010], d[100010];

class cmp {
public:
    bool operator()(const pair<ll, ll>& a, const pair<ll, ll>& b)
    {
        return a.second > b.second;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> t[i];

    for (int i = 1; i <= n; i++)
        cin >> d[i];

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> pq;

    for(int i = 1; i <= n; i++)
        pq.push(make_pair(t[i], t[i] + d[i]));

    while(!pq.empty()) {

    }

    return 0;
}

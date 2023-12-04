#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll x, res = 0;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        pq.push(x);
    }

    while (pq.size() > 1)
    {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();

        res += a + b;
        pq.push(a + b);
    }

    cout << res;
    cout.flush();

    return 0;
}
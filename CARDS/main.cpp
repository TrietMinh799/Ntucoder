#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char type;
int n;
ll x;
priority_queue<ll, vector<ll>> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> type;
        if (type == 'P')
        {
            if (pq.empty())
            {
                cout << -1 << "\n";
                continue;
            }
            int cnt = 0;
            ll maxn = pq.top();
            while (!pq.empty() && pq.top() == maxn)
            {
                cnt++;
                pq.pop();
            }
            cout << maxn << " " << cnt << "\n";
        }
        else
        {
            cin >> x;
            pq.push(x);
        }
    }

    if (pq.empty())
    {
        cout << -1 << "\n";
        return 0;
    }

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout.flush();
    return 0;
}
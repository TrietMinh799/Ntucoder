#include <bits/stdc++.h>

using namespace std;

int n;
long long res = 0;
pair<long long, int> a[100005];

bool cmp(const pair<long long, int>& a, const pair<long long, int>& b) {
    if(a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a + 1, a + n + 1, cmp);

    vector<pair<long long, int>> b;
    for(int i = n; i > n - 3; i--)
        b.push_back(a[i]);

    sort(b.begin(), b.end(), cmp);

    res = b[0].first + 2 * b[1].first + 3 * b[2].first;

    cout << res;

    return 0;
}

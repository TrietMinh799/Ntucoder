#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll s, p, a[44];
int n;
vector<Data> x, y;

void Try(int i, int limit, int cnt) {
    if(i > limit) return;

    x.push_back(make_pair(i, cnt));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s >> p;

    for(int i = 1; i <= n; i++) cin >> a[i];

    Try(1, n / 2, 0);
    Try(n / 2, n, 0);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> ar[100005];
long long b[100005], t[100005] = {0}, res = 0;

int get(int a) {
    long long sum = 0;
    while(a < 100005) {
        sum += t[a];
        a += (a & -a);
    }

    return sum;
}

void sets(int a) {
    while(a > 0) {
        t[a]++;
        a -= (a & -a);
    }
}

void solve() {
    int last = 1e9, cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(ar[i].first != last) {
            last = ar[i].first;
            cnt++;
        }
        b[ar[i].second] = cnt;
    }

    for(int i = 1; i <= n; i++) {
        res += get(b[i] + 1);
        sets(b[i]);
    }

    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> ar[i].first;
        ar[i].second = i;
    }

    sort(ar + 1, ar + n + 1);

    solve();

    return 0;
}

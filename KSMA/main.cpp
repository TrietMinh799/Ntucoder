#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e7;

int n, k, pre, s, c1, c2, m;
vector<int> cnt(MAXN + 1, 0);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> s >> c1 >> c2 >> m;

    pre = s;
    cnt[s]++;
    for(int i = 2; i <= n; i++) {
        int nums = (c1 % m * pre % m + c2) % m;
        cnt[nums]++;
        pre = nums;
    }

    for(int i = 0; k > 0 && i <= MAXN; i++) {
        while(cnt[i]-- && k) {
            k--;
            cout << i << " ";
        }
    }


    return 0;
}

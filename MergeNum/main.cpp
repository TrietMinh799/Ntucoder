#include <bits/stdc++.h>

using namespace std;

string x, y;
long long maxn = 0, minn = 1e18;

void solve(int idx1, int idx2, string nums)
{
    if(nums.size() == x.size() + y.size()) {
        maxn = max(maxn, ((long long) atoll(nums.c_str())));
        minn = min(minn, ((long long) atoll(nums.c_str())));
        return;
    }

    if(idx1 < x.size()) solve(idx1 + 1, idx2, nums + x[idx1]);
    if(idx2 < y.size()) solve(idx1, idx2 + 1, nums + y[idx2]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x >> y;

    solve(0, 0, "");

    cout << minn << "\n" << maxn;

    return 0;
}

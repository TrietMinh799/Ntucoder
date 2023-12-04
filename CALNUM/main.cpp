#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
ll l, r, dp[1500][180][20];

vector<int> getDigits(ll x) {
    vector<int> des;
    while(x != 0) {
        des.push_back(x % 10);
        x /= 10;
    }
    return des;
}

ll counts(ll sum1, ll sum2, int idx, int tight, vector<int>& digits) {
    if(idx == -1) {
        if(__gcd(sum1, sum2) == 1)
            return 1;
        else
            return 0;
    }

    if(dp[sum1][sum2][idx] != -1 && !tight) {
        return dp[sum1][sum2][idx];
    }

    int k = (tight) ? digits[idx] : 9;
    ll ret = 0;

    for(int i = 0; i <= k; i++) {
        int newTight = (i == digits[idx]) ? tight : 0;
        ret += counts(sum1 + i * i, sum2 + i, idx - 1, newTight, digits);
    }

    if(!tight)
        dp[sum1][sum2][idx] = ret;

    return ret;
}

void sovle() {
    cin >> l >> r;

    vector<int> digitsA = getDigits(l - 1),
                digitsB = getDigits(r);

    ll right = counts(0, 0, digitsB.size() - 1, 1, digitsB);
    //memset(dp, -1, sizeof(dp));
    ll left = counts(0, 0, digitsA.size() - 1, 1, digitsA);

    cout << right - left << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    memset(dp, -1, sizeof(dp));
    while(t--)
        sovle();

    return 0;
}

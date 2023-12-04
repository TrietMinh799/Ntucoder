#include <bits/stdc++.h>

using namespace std;

long long n;
int t, k;

long long getBaseSum(long long x) {
    long long sum = 0;
    while(x) {
        sum += x % k;
        x /= k;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;

    while(t--) {
        cin >> n >> k;
        long long curr = getBaseSum(n);
        ++n;
        while(getBaseSum(n) != curr)
            ++n;

        cout << n << "\n";
    }

    return 0;
}

#include <iostream>

using namespace std;

int n, m, k;
long long l = 1, r = 1e11, ans = -1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;

    while (l <= r)
    {
        long long mid = l + (r - l) / 2;
        long long cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cnt += min(mid / i, (long long)m);
        }

        if (cnt >= k)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans;

    return 0;
}
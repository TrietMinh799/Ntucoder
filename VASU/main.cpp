#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

int n;
ll a[2005], curr = 0, res = 0;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n, greater<ll>());

    for (int i = 0; i < n; i++)
    {
        if (a[i] - curr < 0)
            break;
        res += a[i] - curr;
        curr++;
    }

    cout << res << endl;
    return 0;
}
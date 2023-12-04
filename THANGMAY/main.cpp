#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, a[2000], res;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n, greater<int>());

    for (int i = 0; i < n; i += k)
        res += (a[i] - 1) * 2;

    cout << res << " ";

    return 0;
}
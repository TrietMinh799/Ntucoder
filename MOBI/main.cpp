#include <iostream>
#include <vector>

#define ll long long
#define MAXSIZE 1000005

using namespace std;

ll n, k, x, maxSum = 0, sum = 0;
vector<ll> a(MAXSIZE, 0);

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    while (n--)
    {
        cin >> x;
        cin >> a[x];
    }

    ll start = 0, finish = min(2 * k, (ll)MAXSIZE);

    for (ll i = start; i <= finish; ++i)
        sum += a[i];

    maxSum = sum;
    start++;
    finish++;

    while (finish <= MAXSIZE)
    {
        sum -= a[start - 1];
        sum += a[finish];
        maxSum = max(maxSum, sum);
        start++;
        finish++;
    }

    cout << maxSum;

    return 0;
}
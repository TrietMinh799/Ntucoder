#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a;

    // a * a + b * b = c * c => a * a = (c - b) * (c + b)
    // sqrt(n)
    for(ll i = 1; i < a; i++)
    {
        if((a * a) % i == 0)
        {
            ll b = i, c = (a * a) / i;
            if((b + c) % 2 == 0 && (max(b, c) - min(b, c)) / 2 > a)
                res++;
        }
    }

    printf("%lld", res);

    return 0;
}

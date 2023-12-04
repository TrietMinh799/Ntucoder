#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b, c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> a >> b >> c)
    {
        if (!a && !b && !c)
            break;
        if (b - a == c - b)
        {
            printf("%s %lld \n", "AP", c + (c - b));
        }
        else
        {
            printf("%s %lld \n", "GP", c * (c / b));
        }
    }

    return 0;
}
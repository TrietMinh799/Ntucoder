#include <iostream>

using namespace std;

long long n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    if (n == 1)
    {
        cout << 1;
        return 0;
    }

    long long res = 1, vt = 1;
    for (int i = 2; i <= 500000; i++)
    {
        res = (res / i + 1) * i;
        vt++;
        if (vt == n)
        {
            cout << res;
            return 0;
        }

        for (int j = 1; j <= i - 1; j++)
        {
            res += i;
            vt++;
            if (vt == n)
            {
                cout << res << "\n";
                return 0;
            }
        }
    }

    return 0;
}
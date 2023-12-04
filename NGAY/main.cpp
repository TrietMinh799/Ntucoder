#include <bits/stdc++.h>

using namespace std;

int d, t, n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> d >> t >> n;

    if(t == 12 && d == 31) {
        cout << 1 << " " << 1 << " " << n + 1;
        return 0;
    }

    if(t == 2)
    {
        if((n % 4 == 0 && (n % 100 != 0)) || n % 400 == 0)
        {
            if(d < 29)
                cout << d + 1 << " " << t << " " << n;
            else
                cout << 1 << " " << t + 1 << " " << n;
            return 0;
        } else {
            if(d < 28)
                cout << d + 1 << " " << t << " " << n;
            else
                cout << 1 << " " << t + 1 << " " << n;
            return 0;
        }
    }
    else
    {
        if(t == 1 || t == 3 | t == 5 || t == 7 || t == 8 || t == 10 || t == 12) {
            if(d < 31) {
                cout << d + 1 << " " << t << " " << n;
            } else {
                cout << 1 << " " << t + 1 << " " << n;
            }
        } else {
            if(d < 30) {
                cout << d + 1 << " " << t << " " << n;
            } else {
                cout << 1 << " " << t + 1 << " " << n;
            }
        }
    }

    return 0;
}

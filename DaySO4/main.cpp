#include <bits/stdc++.h>

using namespace std;

int n, a[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 22, 30, 41, 50, 61, 70, 81, 90, 111};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    if(n < 20)
    {
        cout << a[n];
        return 0;
    }

    n -= 20;
    int idx = n / 8 + 2;
    int heso = n % 8 + 2;
    if(n % 2 == 0)
    {
        cout << heso;
        for(int i = 0; i < idx; i++)
            cout << 0;
    }
    else
    {
        cout << heso;
        for(int i = 0; i < idx; i++)
            cout << 1;
    }
    return 0;
}

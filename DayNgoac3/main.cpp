#include <iostream>
#include <cstring>

#define MAXSIZE 100011

using namespace std;

int n, f[MAXSIZE], a[MAXSIZE];
string brackets;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> brackets;

    for (int i = 0; i < n; i++)
    {
        if (brackets[i] == '(')
            a[i] = 1;
        else
            a[i] = -1;
    }

    return 0;
}
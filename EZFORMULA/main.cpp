#include <iostream>

using namespace std;

int f[10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 10; i++)
        cin >> f[i];

    int ans = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            int v = f[i] | f[j];
            ans ^= v;
        }
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            for (int z = j + 1; z < 10; z++)
            {
                int v = f[i] | f[j] | f[z];
                ans ^= v;
            }
        }
    }

    for (int i = 0; i < 7; i++)
    {
        for (int j = i + 1; j < 8; j++)
        {
            for (int z = j + 1; z < 9; z++)
            {
                for (int k = z + 1; k < 10; k++)
                {
                    int v = f[i] | f[j] | f[z] | f[k];
                    ans ^= v;
                }
            }
        }
    }

    cout << ans;

    return 0;
}
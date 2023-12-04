#include <iostream>
#include <string>

using namespace std;

int n;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string res = "";
        res += (i % 2 == 0 ? "W" : "B");
        if (res == "W")
            for (int j = 1; j < n; j++)
                res += (j % 2 == 0 ? "W" : "B");
        else
            for (int j = 1; j < n; j++)
                res += (j % 2 == 1 ? "W" : "B");
        cout << res << endl;
    }

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

int res = 0;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    getline(cin, s);

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            res++;
    }

    cout << res + 1;
    return 0;
}

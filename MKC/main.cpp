#include <iostream>
#include <string>

using namespace std;

long long res = 0;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;

    for (int i = 0; i < s.size(); i++)
        res += s[i] - '0';

    cout << res << endl;

    return 0;
}
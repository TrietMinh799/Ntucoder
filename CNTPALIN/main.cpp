#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll t, l, r;

bool check(ll x)
{
    string s = to_string(x);
    string temp = s;
    reverse(temp.begin(), temp.end());

    return temp == s;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--)
    {
        cin >> l >> r;
        if (l > r)
            swap(l, r);
        ll res = 0;
        for (ll i = l; i <= r; i++)
        {
            if (check(i))
                res++;
        }

        cout << res << endl;
    }

    return 0;
}
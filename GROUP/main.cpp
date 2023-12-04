#include <iostream>

using namespace std;

typedef long long ll;

int t, n;
const int mod = 1e9 + 7;
ll f[1100];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;

    f[0] = 1;
    for(int i = 1; i <= 1000; i++) {
        for(int j = 2; j <= 1000; j++) {
            if(j >= i) {
                f[j] = (f[j] + f[j - i]) % mod;
            }
        }
    }

    while(t--) {
        cin >> n;
        cout << f[n] << "\n";
    }

    return 0;
}

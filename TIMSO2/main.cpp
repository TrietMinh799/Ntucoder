#include <bits/stdc++.h>

using namespace std;

long long n, cnt[10] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    if(n == 0) {
        cout << 10;
        return 0;
    }

    if(n == 1) {
        cout << 1;
        return 0;
    }

    while(n % 2 == 0) {
        n /= 2;
        cnt[2]++;
    }

    for(long long i = 3; i * i <= n; i += 2) {
        if(i >= 10) break;
        while(n % i == 0) {
            n /= i;
            cnt[i]++;
        }
    }

    if(n >= 10) {
        cout << -1;
        return 0;
    }

    while(cnt[2] && cnt[3]) {
        cnt[2]--;
        cnt[3]--;
        cnt[6]++;
    }

    for(int i = )


    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n, a, t[2000005] = {0};
long long ans = 0;

int retrieve(int a) {
    int sum = 0;
    while(a < 2000005) {
        sum += t[a];
        a += (a&-a);
    }

    return sum;
}

void update(int a) {
    while(a > 0) {
        t[a]++;
        a -= (a&-a);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a;
        ans += retrieve(a + 1);
        update(a);
    }

    cout << ans;

    return 0;
}

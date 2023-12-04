#include <bits/stdc++.h>

using namespace std;

int n, m, q[100005];
bool visited[100005] = {false};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        cin >> q[i];
    }

    for(int i = m; i >= 1; i--) {
        if(!visited[q[i]]) {
            cout << q[i] << " ";
            visited[q[i]] = true;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            cout << i << " ";
        }
    }

    return 0;
}

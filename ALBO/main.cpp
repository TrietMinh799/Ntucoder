#include <bits/stdc++.h>

using namespace std;

int n, k;

int main()
{
    scanf("%d %d", &n, &k);

    if(n % (k + 1) != 0) {
        printf("Alice will win");
    } else {
        printf("Bob will win");
    }
    return 0;
}

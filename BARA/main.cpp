#include <iostream>
#include <cmath>

using namespace std;

int n, k;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    cout << (k >= n ? 10 : ceil(((2.0 * n) / k)) * 5) << endl;

    return 0;
}
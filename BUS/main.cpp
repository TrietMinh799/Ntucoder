#include <bits/stdc++.h>

using namespace std;

int n;

vector<string> result =
{
    "+------------------------+",
    "|O.O.O.O.O.O.O.#.#.#.#.|D|)",
    "|O.O.O.O.O.O.#.#.#.#.#.|.|",
    "|O.......................|",
    "|O.O.O.O.O.O.#.#.#.#.#.|.|)",
    "+------------------------+"
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for (int i = 1 ; i <= 34 ; i++)
    {
        char c = i > n ? '#' : 'O';
        int row = i <= 4 ? 0 : (i - 2) / 3;
        int seat = i <= 4 ? i - 1 : (i - 5) % 3;
        if (seat == 2 && row != 0) seat++;
        result[1 + seat][1 + row * 2] = c;
    }
    for (auto s : result) cout << s << "\n";
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int y, x;
int board[8][8] = {0};

void printBoard() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cout << (board[i][j] ? "w" : ".");
        }

        cout << "\n";
    }
}

bool isSafe(int row, int col) {
    int i, j;

    for(i = 0; i < col; i++)
        if(board[row][i])
            return false;

    for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j])
            return false;

    for(i = row, j = col; j >= 0 && i < 8; i++, j--)
        if(board[i][j])
            return false;

    return true;
}

bool solve(int col) {
    if(col >= 8)
        return true;

    for(int i = 0; i < 8; i++) {
        if(isSafe(i, col)) {
            board[i][col] = 1;
            if(solve(col + 1))
                return true;
            board[i][col] = 0;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x >> y;
    x--;
    y--;
    board[x][y] = 1;
    solve(0);

    printBoard();

    return 0;
}

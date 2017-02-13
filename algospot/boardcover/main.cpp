#include <iostream>
#include <cstdio>
using namespace std;
int C, H, W;
bool board[20][20];

int count(int i, int j) {
    if (i==H-1) {
        for (int s=0; s<W; s++) if(board[i][s]) return 0;
        return 1;
    }
    if (j == W)
        return count(i+1, 0);
    if (!board[i][j])
        return count(i, j+1);
    int ret = 0;
    board[i][j] = false;
    // #.
    // ..
    if (j>0 && board[i+1][j-1] && board[i+1][j]) {
        board[i+1][j-1] = board[i+1][j] = false;
        ret += count(i,j+1);
        board[i+1][j-1] = board[i+1][j] = true;
    }
    // ..
    // #.
    if (j<W-1 && board[i][j+1] && board[i+1][j+1]) {
        board[i][j+1] = board[i+1][j+1] = false;
        ret += count(i,j+1);
        board[i][j+1] = board[i+1][j+1] = true;
    }
    // .#
    // ..
    if (j<W-1 && board[i+1][j] && board[i+1][j+1]) {
        board[i+1][j] = board[i+1][j+1] = false;
        ret += count(i,j+1);
        board[i+1][j] = board[i+1][j+1] = true;
    }
    // ..
    // .#
    if (j<W-1 && board[i][j+1] && board[i+1][j]) {
        board[i][j+1] = board[i+1][j] = false;
        ret += count(i,j+1);
        board[i][j+1] = board[i+1][j] = true;
    }
    board[i][j] = true;
    return ret;
}
int main() {
    char tmp;
    cin >> C;
    while(C--) {
        cin >> H >> W;
        for (int i=0; i<H; i++)
            for (int j=0; j<W; j++) {
                cin >> tmp;
                // true if empty
                board[i][j] = (tmp =='.');
            }
        cout << count(0,0) << endl;
    }
    return 0;
}

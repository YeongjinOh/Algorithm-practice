#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int C;
char state[3][3];
char check(int n) {
    for (int i=0; i<3; i++) {
        if (state[i][0] == state[i][1] && state[i][1] == state[i][2] && state[i][0] != '.') return state[i][0];
        if (state[0][i] == state[1][i] && state[1][i] == state[2][i] && state[0][i] != '.') return state[0][i];
    }
    if (state[0][0] == state[1][1] && state[1][1] == state[2][2] && state[2][2] != '.') return state[2][2];
    if (state[2][0] == state[1][1] && state[1][1] == state[0][2] && state[0][2] != '.') return state[0][2];
    if (n == 9)
        return '.';
    // check
    bool win = false, lose = false, draw = false;
    char me = n%2==0?'x':'o', you=n%2==0?'o':'x';
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (state[i][j] == '.') {
                state[i][j] = me;
                char chk = check(n+1);
                if (chk == me) win = true;
                if (chk == you) lose = true;
                if (chk == '.') draw = true;
                state[i][j] = '.';
            }
        }
    }
    if (win == true) return me;
    if (draw == true) return '.';
    return you;
}
int main() {
    cin >> C;
    while (C--) {
        int cnt = 0;
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                cin >> state[i][j];
                if (state[i][j] != '.') cnt++;
            }
        }
        char res = check(cnt);
        if (res == '.') cout << "TIE" << endl;
        else cout << res << endl;
    }
}

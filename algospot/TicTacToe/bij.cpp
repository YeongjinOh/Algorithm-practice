// use bijection to match DP index and state
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int C;
int cache[3*3*3*3*3*3*3*3*3];
char state[3][3];
int charToInt (char c) {
    if (c == 'x') return 0;
    if (c == 'o') return 1;
    return 2;
}
// biject from this state to idx of cache
int bijection () {
    int res = 0;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++) {
            res *= 3;
            res += charToInt(state[i][j]);
        }
    return res;
}
int check(int n) {
    int &ret = cache[bijection()];
    if (ret != -1) return ret;

    for (int i=0; i<3; i++) {
        if (state[i][0] == state[i][1] && state[i][1] == state[i][2] && state[i][0] != '.') return charToInt(state[i][0]);
        if (state[0][i] == state[1][i] && state[1][i] == state[2][i] && state[0][i] != '.') return charToInt(state[0][i]);
    }
    if (state[0][0] == state[1][1] && state[1][1] == state[2][2] && state[2][2] != '.') return charToInt(state[2][2]);
    if (state[2][0] == state[1][1] && state[1][1] == state[0][2] && state[0][2] != '.') return charToInt(state[0][2]);
    if (n == 9)
        return charToInt('.');
    // check
    bool win = false, lose = false, draw = false;
    char me = n%2==0?'x':'o', you=n%2==0?'o':'x';
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (state[i][j] == '.') {
                state[i][j] = me;
                int chk = check(n+1);
                if (chk == charToInt(me)) win = true;
                if (chk == charToInt(you)) lose = true;
                if (chk == charToInt('.')) draw = true;
                state[i][j] = '.';
            }
        }
    }
    if (win == true) return charToInt(me);
    if (draw == true) return charToInt('.');
    return charToInt(you);
}
int main() {
    cin >> C;
    memset(cache,-1,sizeof(cache));
    while (C--) {
        int cnt = 0;
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                cin >> state[i][j];
                if (state[i][j] != '.') cnt++;
            }
        }
        int res = check(cnt);
        if (res == 2) cout << "TIE" << endl;
        else if (res == 1) cout << "o" << endl;
        else cout << "x" << endl;
    }
}

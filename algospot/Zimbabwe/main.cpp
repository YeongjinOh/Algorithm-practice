#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define INF 987654321
#define MOD 1000000007
using namespace std;
int C, m, len;
string e;
bool visit[15];

bool isMod(string price) {
    long long sum = stoll(price);
    return sum%m == 0;
}
int count (string price) {
    if (price.length() == len) {
        if (price < e && isMod(price)) return 1;
        return 0;
    }
    int ret = 0;
    bool digit[10];
    memset(digit,0,sizeof(digit));
    for (int i=0; i<len; ++i) {
        if (digit[e[i]-'0'])
            continue;
        bool& v = visit[i];
        if (!v) {
            v = true;
            ret = (ret + count(price+e[i]))%MOD;
            v = false;
            digit[e[i]-'0'] = true;
        }
    }
    return ret;
}

int main() {
    cin >> C;
    while (C--) {
        cin >> e >> m;
        len = e.length();
        memset(visit,0,sizeof(visit));
        cout << count("") <<endl;
    }
}

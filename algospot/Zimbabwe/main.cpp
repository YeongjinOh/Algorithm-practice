#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define INF 987654321
#define MOD 1000000007
using namespace std;
int C, m, len;
string e;

// 2 by 2^14 by m
// i is bool which means price smaller than e // j = visit(1101010101) //  k = price[1:len] % m
int cache[2][1024*16][20];

// smaller means higher digits of price is already smaller than e,
// so no need to compare
// suppose that price[1:k] == e[1:k] if !smaller
//              price[1:k] < e[1:k] if smaller
int count (string price, int visit, int mod, bool smaller) {
    int &ret = cache[smaller][visit][mod];
    if (ret != -1) return ret;

    if (price.length() == len) {
        if (smaller && mod == 0) return 1;
        return 0;
    }
    ret = 0;
    bool digit[10];
    memset(digit,0,sizeof(digit));
    for (int i=0; i<len; ++i) {
        int d = e[i]-'0';
        if (digit[d] || visit & (1<<i))
            continue;
        if (!smaller && e[price.length()] < e[i])
            continue;
        int nextMod = ((mod*10)+d)%m;
        ret += count(price+e[i], visit+(1<<i), nextMod%m, smaller || e[price.length()] > e[i]);
        ret = ret % MOD;
        digit[d] = true;
    }
    return ret;
}

int main() {
    cin >> C;
    while (C--) {
        cin >> e >> m;
        len = e.length();
        memset(cache,-1,sizeof(cache));
        cout << count("",0,0, false) <<endl;
    }
}

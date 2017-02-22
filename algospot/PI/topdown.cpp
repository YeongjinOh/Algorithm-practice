#include <iostream>
#include <cstring>
#define MAX_LEN 10005
#define INF 987654321
using namespace std;
int C,n;
string pi;
int d[MAX_LEN];
int cache[MAX_LEN];

int getLevel (int start, int len) {
    bool l1 = true, l21 = true, l22 = true, l4 = true;
    char fc = pi[start]; // first character
    int diff = pi[start+1] - pi[start];
    for (int i=start+1; i<start+len; ++i) {
        if (pi[i] != fc)
            l1 = false;
        if (pi[i]-pi[i-1] != 1)
            l21 = false;
        if (pi[i]-pi[i-1] != -1)
            l22 = false;
        if (pi[i]-pi[i-1] != diff)
            l4 = false;
    }
    if (l1)
        return 1;
    if (l21 || l22)
        return 2;
    bool l3 = true;
    for (int i=start+2; i<start+len; ++i) {
        if (pi[start+(i-start)%2] != pi[i])
            l3 = false;
    }
    if (l3)
        return 4;
    if (l4)
        return 5;
    return 10;
}

int min (int a, int b) { return a>b?b:a; }
int min3 (int a, int b, int c) { return min(a,min(b,c)); }

// from 0 to n-1
int get (int i) {
    if (i == n)
        return 0;
    int &ret = cache[i];
    if (ret != -1) return ret;
    ret = INF;
    for (int l=3; l<=5; l++) {
        if (i+l <=n)
            ret = min (ret, get(i+l)+getLevel(i,l));
    }
    return ret;
}
int main() {
    cin >> C;
    while (C--) {
        cin >> pi;
        n = pi.size();
        memset(cache,-1,sizeof(cache));
        cout << get(0) << endl;
    }
}

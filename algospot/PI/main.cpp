#include <iostream>
#include <cstring>
#define MAX_LEN 10005
#define INF 987654321
using namespace std;
int C,n;
char pi[MAX_LEN];
int d[MAX_LEN];

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
int main() {
    cin >> C;
    while (C--) {
        cin >> pi;
        d[0] = 0;
        d[1] = d[2] = INF;
        d[3] = getLevel(0,3);
        d[4] = getLevel(0,4);
        for (int i=5; i<=strlen(pi); ++i) {
            d[i] = min3(d[i-3]+getLevel(i-3,3),d[i-4]+getLevel(i-4,4),d[i-5]+getLevel(i-5,5));
        }
        cout << d[strlen(pi)] << endl;
    }
}

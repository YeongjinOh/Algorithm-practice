#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 1000001000
using namespace std;
int C;
int n,p,l;
int calc[51];

int max (int a, int b) { return a>b?a:b; }
int min (int a, int b) { return a<b?a:b; }
void callY (int k, int start, int end);

void callX (int k, int start, int end) {
    if (start > end) return;
    if (k == 0) {
        cout << "X";
        return;
    }
    if (start <= calc[k-1])
        callX(k-1, start, min(calc[k-1], end));
    if (start <= calc[k-1]+1 && end >= calc[k-1]+1)
        cout << "+";
    if (end >= calc[k-1]+2)
        callY(k-1, max(start-calc[k-1]-1, 1), min(calc[k-1],end-calc[k-1]-1));
    if (end >= calc[k])
        cout << "F";
}
void callY (int k, int start, int end) {
    if (start > end) return;
    if (k == 0 && start <= 1 && end >= 1) {
        cout << "Y";
        return;
    }
    if (start == 1)
        cout << "F";
    if (start <= calc[k-1]+1)
        callX(k-1, max(1,start-1), min(calc[k-1], end-1));
    if (start <= calc[k-1]+2 && end >= calc[k-1]+2)
        cout << "-";
    if (end >= calc[k-1]+3)
        callY(k-1, max(start-calc[k-1]-2, 1), end-calc[k-1]-2);
}
int main() {
    cin >> C;
    calc[0] = 1;
    for (int i=1; i<=50; ++i) {
        calc[i] = 2*calc[i-1]+2;
        if (calc[i] > MAX) calc[i] = MAX;
    }
    while (C--) {
        cin >> n >> p >> l;
        if (p == 1) {
            cout << "F";
            p++;
            l--;
        }
        callX(n, p-1, l+p-2);
        cout << endl;
    }
}

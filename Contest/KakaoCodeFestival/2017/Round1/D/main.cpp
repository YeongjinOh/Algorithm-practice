#include <iostream>
#include <vector>
#include <map>
typedef long long ll;
using namespace std;

void get(int n, int pn, vector<ll> &th, map<ll, int> &ts, int &cnt) {
    if (n % 3 != 0 || n < 3) return;
    if (pn > 40 || th[pn/2] > n) return;
    if ((n == 3 && pn == 0)) {
        cnt++;
        return;
    }
    if (ts[n] > 0) {
        if (pn == ts[n]*2) cnt++;
        return;
    }
    if (pn < 2) return;
    n /= 3;
    pn -= 2;
    for (int i=0; i+pn<40; i++)
        get(n-i, i+pn, th, ts, cnt);
}
int solution(int n) {
    if (n < 5) return 0;
    vector<ll> th(20);
    map<ll, int> ts;
    th[0] = 1;
    for (int i=1; i<20; i++) {
        th[i] = th[i-1]*3;
        ts[th[i]] = i;
    }
    int cnt = 0;
    for (int i=0; i<40; i++)
        get(n-i, i, th, ts, cnt);

    return cnt;
}

int main() {
    int n; cin >> n;
    cout << solution(n) << endl;
    return 0;
}

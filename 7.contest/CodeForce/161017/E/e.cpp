#include <set>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
const int INF = 1e9+7;
const int SIZE = 1e6+7;

#define RI(X) scanf("%d", &X);
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y);
#define PI(X) printf("%d ", X);
#define PPI(X) printf("(%d,%d)", X.first, X.second);
#define PNL() printf("\n"); // print new line
#define REP(I, N) for(int I=0; I<N; ++I)
#define FORI(S, E) for(int i=S; i<E; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define Pvpii(VEC, i) { printf("(%d,%d)\n", VEC[i].fi, VEC[i].se); }

// c의 max값을 먼저 찾고, 그 다음 u의 최소값.
int c, u;  // maximum number of computers, minimum number of adapters when c is maximal
int aa[SIZE], bb[SIZE]; // number of adapters of each socket, index of socket of each computer

set<pii> p;
int main () {
    DRII(n, m);
    p.insert(mp(INF,0));
    vpii s;
    int tmp;
    REP(i, n) {
        RI(tmp);
        p.insert(mp(tmp, i+1));
    }
    REP(i, m) {
        RI(tmp);
        s.pb(mp(tmp, i+1));
    }

    sort(s.begin(), s.end());

    for (int i=0; i< s.size(); i++) {
        // s[i] = current socket
        int x = s[i].fi; // socket power
        int id = s[i].se; // socket index
        int cnt = 0; // number of adapter
        while(1) {
            // lower bound를 이용해서 같은 값 찾기!
            set<pii>::iterator it = p.lower_bound(mp(x, 0));
            if (it->fi == x) {
                c++;
                u += cnt;
                bb[it->se] = id;
                aa[id] = cnt;
                p.erase(it);
                break;
            }
            if (x==1) break;
            cnt++;
            x = (x+1)/2;
        }
    }
    PI(c); PI(u);
    PNL();
    REP(i, m)
        PI(aa[i+1]);
    PNL();
    REP(i, n)
        PI(bb[i+1]);
    PNL();
    return 0;
}

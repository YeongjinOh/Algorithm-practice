#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 98754321

void solve () {
    int N, R, O, Y, G, B, V;
    cin >> N >> R >> O >> Y >> G >> B >> V;
    // G -> R / O -> B / V -> Y
    if (G > R || O > B || V > Y) {
        cout << "IMPOSSIBLE";
        return;
    }
    if (G == R && N == G + R) {
        for (int i=0; i<G; i++) printf("GR");
        return;
    }
    if (O == B && N == O + B ) {
        for (int i=0; i<O; i++) printf("OB");
        return;
    }
    if (V == Y && N == V + Y) {
        for (int i=0; i<V; i++) printf("VY");
        return;
    }
    if ((G > 0 && G == R) || (O == B && O > 0) || (V == Y && V > 0)) {
        cout << "IMPOSSIBLE";
        return;
    }
    // now, G < R && O < B && V < Y
    int r = R-G, y = Y-V, b = B-O;
    if (r+y<b || y+b<r || b+r<y) {
        cout << "IMPOSSIBLE";
        return;
    }
    vector<int> circle;
    int most = max<int>(r, max<int>(y, b)), nxt;
    if (most == r) nxt = 0;
    else if (most == y) nxt = 1;
    else nxt = 2;
    while(r+b+y) {
        circle.push_back(nxt);
        if (r+b+y == 3) {
            if (nxt == 0) {
                r--;
                if (circle[0] == 1 && y > 0) nxt = 1;
                else if (circle[0] == 2 && b > 0) nxt = 2;
                else nxt = b<y?1:2;
            } else if (nxt == 1) {
                y--;
                if (circle[0] == 2 && b > 0) nxt = 2;
                else if (circle[0] == 0 && r > 0) nxt = 0;
                else nxt = b<r?0:2;
            } else {
                b--;
                if (circle[0] == 1 && y > 0) nxt = 1;
                else if (circle[0] == 0 && r > 0) nxt = 0;
                else nxt = r<y?1:0;
            }
        }
        else if (nxt == 0) {
            r--;
            nxt = b<y?1:2;
        } else if (nxt == 1) {
            y--;
            nxt = b<r?0:2;
        } else {
            b--;
            nxt = r<y?1:0;
        }
    }
    string res = "";
    int g=G, v=V, o=O;
    for (int i=0; i<circle.size(); i++) {
        if (circle[i] == 0) {
            printf("R");
            res += "R";
            while(g-- > 0) { res += "GR"; printf("GR"); }
        } else if (circle[i] == 1) {
            printf("Y");
            res+="Y";
            while(v-- > 0) { res+="VY"; printf("VY"); }
        } else if (circle[i] == 2) {
            printf("B");
            res+="B";
            while(o-- > 0) { res+="OB"; printf("OB"); }
        }
    }
    for (int i=0; i<res.size(); i++) {
        switch(res[i]) {
            case 'R':
                R--;
                break;
            case 'B':
                B--;
                break;
            case 'Y':
                Y--;
                break;
            case 'G':
                G--;
                break;
            case 'V':
                V--;
                break;
            case 'O':
                O--;
                break;
        }
    }
//    printf("\n%d %d %d %d %d %d\n", R, B, Y, G, V, O);
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
    return 0;
}

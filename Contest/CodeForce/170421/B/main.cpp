#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
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

string str[51];


int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) cin >> str[i];
    int sz = str[0].size();

    int minVal = 9876543;
    for (int start=0; start<n; start++) {
        int curSum = 0;
        for (int i=0; i<n; i++) {
            int cur = 987654;
            if (i != start) {
                for (int offset=0; offset<sz; offset++) {
                    bool pos = true;
                    for (int j=0; j<sz; j++) {
                        if (str[start][j] != str[i][(offset+j)%sz]) {
                            pos = false;
                            break;
                        }
                    }
                    if (pos) {
                        cur = offset;
                        break;
                    }
                }
                curSum += cur;
            }
        }
        if (curSum < minVal) minVal = curSum;
    }
    if (minVal < 987654) cout << minVal << endl;
    else cout << -1 << endl;

    return 0;
}

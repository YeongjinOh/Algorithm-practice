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
#define INF 5e18

int t;

string str1, str2;
long long minDiff = INF;
long long minA = 0, minB = 0;
void back(long long a, long long b, int i) {
    if (i == str1.size()) {
        ll diff = abs<ll>(a-b);
        if (diff < minDiff || (diff == minDiff && b < minB)) {
            minDiff = diff;
            minA = a; minB = b;
        }
        return;
    }
    if (a > b) {
        a = a*10 + (str1[i]=='?'?0:str1[i]-'0');
        b = b*10 + (str2[i]=='?'?9:str2[i]-'0');
        back(a,b,i+1);
    } else if (a < b) {
        a = a*10 + (str1[i]=='?'?9:str1[i]-'0');
        b = b*10 + (str2[i]=='?'?0:str2[i]-'0');
        back(a,b,i+1);
    } else if (a == b) {
        if (str1[i] == '?' && str2[i] == '?') {
            back(a*10, b*10, i+1);
            back(a*10+1, b*10, i+1);
            back(a*10, b*10+1, i+1);
        } else if (str1[i] == '?') {
            int inc = str2[i]-'0';
            back(a*10+((inc+9)%10), b*10+inc, i+1);
            back(a*10+inc, b*10+inc, i+1);
            back(a*10+((inc+1)%10), b*10+inc, i+1);
        } else if (str2[i] == '?') {
            int inc = str1[i]-'0';
            back(a*10+inc, b*10+((inc+9)%10), i+1);
            back(a*10+inc, b*10+inc, i+1);
            back(a*10+inc, b*10+((inc+1)%10), i+1);
        } else {
            back(a*10+(str1[i]-'0'), b*10+(str2[i]-'0'), i+1);
        }
    }
}

void solve () {
    cin >> str1 >> str2;
    minDiff = INF;
    minA = 0, minB = 0;
    back(0, 0, 0);
    for (int i=str1.size()-1; i>=0; i--) {
        str1[i] = '0'+minA%10;
        str2[i] = '0'+minB%10;
        minA/=10;minB/=10;
    }
    cout << str1 << " " << str2;
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
    return 0;
}

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
//////////////////////////////////////////////////////////////////////////
//
// 문제를 잘못 이해했었다.
// input string을 다 쓰는 digit 조합을 찾는 것이므로, 정답은 정해져있다.
// -> Unique한 character를 가진 숫자부터 없애기
///////////////////////////////////////////////////////////////////////

ll t, n, a, b, c;
string str;
int cnt[26];
void read() {
    cin >> str;
}
int take(string c) {
    int m = 987654321;
    rep(i,0,c.size())
        m = min<int>(m, cnt[c[i]-'A']);
    if (c[0] == c[1])
        m = min<int>(m, cnt[c[0]-'A']/2);
    rep(i,0,c.size())
        cnt[c[i]-'A']-=m;
    return m;
}
void solve () {
    memset(cnt,0,sizeof(cnt));
    for (int i=0; i<str.size(); i++) {
        cnt[str[i]-'A']++;
    }
    // "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
    pair<int,string> nums[10] = {
        mp(0,"ZERO"), // Z is unique
        mp(2,"TWO"), // W
        mp(6,"SIX"), // X
        mp(8,"EIGHT"), // G
        mp(4,"FOUR"), // R
        mp(1,"ONE"), // O
        mp(5,"FIVE"), //F
        // 중복되는 charater는 제일 앞에 위치시킨다.
        mp(7,"EESVN"), //S
        mp(3,"EETHR"), //T
        mp(9,"NNIE")
    };

    int res[10];
    rep(i,0,10) res[i] = 0;
    rep(i,0,10)
        res[nums[i].first] += take(nums[i].second);
    /* previous
    for (int i=0; i<10; i+=2) {
        res[i] += take(nums[i]);
        if (i==8) i=-1;
    }
    */
    rep(i,0,10)
        rep(j,0,res[i])
            cout << i;
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        read();
        solve();
        cout << endl;
    }
    return 0;
}

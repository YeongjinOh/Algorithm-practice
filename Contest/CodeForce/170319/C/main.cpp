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
ll n, k, l, r, a, b;

string names[51] = {"Aa", "Ab", "Ac", "Ad", "Ae", "Af", "Ag", "Ah", "Ai", "Aj",
"Ba", "Bb", "Bc", "Bd", "Be", "Bf", "Bg", "Bh", "Bi", "Bj",
"Ca", "Cb", "Cc", "Cd", "Ce", "Cf", "Cg", "Ch", "Ci", "Cj",
"Da", "Db", "Dc", "Dd", "De", "Df", "Dg", "Dh", "Di", "Dj",
"Ea", "Eb", "Ec", "Ed", "Ee", "Ef", "Eg", "Eh", "Ei", "Ej", "Ekk"};

int idx[50];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    string str;
    memset(idx, -1, sizeof(idx));
    int cnt = 0;
    for (int i=0; i<n-k+1; i++) {
        cin >> str;
        if (str[0] == 'N') {
            if (idx[i] == -1) {
                idx[i+k-1] = cnt;
                idx[i] = cnt;
                cnt++;
            } else {
                idx[i+k-1] = idx[i];
            }
        }
    }
    for (int i=0; i<n; i++) {
        if (idx[i] == -1)
            idx[i] = cnt++;
        printf("%s ", names[idx[i]].c_str());
    }
    printf("\n");
    return 0;
}

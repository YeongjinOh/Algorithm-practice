#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = (int) 1e6 + 6, mod = (int) 0;
int n, mark[N], val[N], cl[N], cr[N], root, sr[N];
// 현재 위치에서 sr[b]~sr[e]에 해당하는 애들을 찾고 있어.
int solve(int v, int b, int e) {
    printf("v:%d val[v]:%d cl[v]:%d cr[v]:%d b:%d e:%d \n", v, val[v], cl[v], cr[v], b, e);
	if (e - b <= 0) return 0;
	if (v == -1) return e - b;
	int ml = lower_bound(sr + b, sr + e, val[v]) - sr;
	int mr = upper_bound(sr + b, sr + e, val[v]) - sr;
    printf("ml:%d mr:%d\n", ml, mr);
	return solve(cl[v], b, ml) + solve(cr[v], mr, e);
}
int main() {
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> val[j] >> cl[j] >> cr[j];
		if (cl[j] >= 0) cl[j]--, mark[cl[j]] = 1;
		if (cr[j] >= 0) cr[j]--, mark[cr[j]] = 1;
		sr[j] = val[j];
	}
	sort(sr, sr + n);
	for (int j = 0; j < n; ++j)
		if (!mark[j])
			root = j;
	cout << solve(root, 0, n) << endl;
}


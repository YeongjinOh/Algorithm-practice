#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int abs(int a) {
    return a>0?a:-a;
}
int diff(int a, int b) {
    return abs(a-b);
}
int solution(int n, vector<vector<int> > data) {
    set<int> x, y;
    for (int i=0; i<n; i++) {
        x.insert(data[i][0]);
        y.insert(data[i][1]);
    }
    map<int,int> xpos, ypos;
    int pos = 0;
    for (set<int>::iterator it = x.begin(); it != x.end(); it++, pos++) {
        xpos[*it] = pos;
    }
    pos = 0;
    for (set<int>::iterator it = y.begin(); it != y.end(); it++, pos++) ypos[*it] = pos;
    int yn = y.size(), xn = x.size();
    vector<vector<int> > dp(yn, vector<int> (xn, 0));
    for (int i=0; i<n; i++) {
        int x0 = data[i][0], y0 = data[i][1];
        int x1 = xpos[x0], y1 = ypos[y0];
        dp[y1][x1]++;
    }
    for (int i=0; i<yn; i++) {
        for (int j=0; j<xn; j++) {
            if (i > 0)
                dp[i][j] += dp[i-1][j];
            if (j > 0)
                dp[i][j] += dp[i][j-1];
            if (i > 0 && j > 0)
                dp[i][j] -= dp[i-1][j-1];
        }
    }
    int answer = 0;
    for (int i=0; i<n; i++) {
        int xi = xpos[data[i][0]], yi = ypos[data[i][1]];
        for (int j=i+1; j<n; j++) {
            int xj = xpos[data[j][0]], yj = ypos[data[j][1]];
            if (xj == xi || yi == yj) continue;
            if (diff(xi,xj) == 1 || diff(yi,yj) == 1) {
                answer++;
                continue;
            }
            int x0 = min(xi, xj), x1 = max(xi, xj)-1;
            int y0 = min(yi, yj), y1 = max(yi, yj)-1;
            int sum = dp[y1][x1] - dp[y0][x1] - dp[y1][x0] + dp[y0][x0];
            if (sum == 0)
                answer++;
        }
    }
    return answer;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > p;
    for (int i=0; i<n; i++) {
        vector<int> h(2);
        cin >> h[0] >> h[1];
        p.push_back(h);
    }
    cout << solution(n, p) << endl;
    return 0;
}

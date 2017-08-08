#include <vector>
#include <iostream>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int> > city_map) {
    int answer = 0;
    vector<vector<int> > right(m, vector<int> (n, 0)), down(m, vector<int> (n, 0));
    right[0][0] = 1;
    down[0][0] = 1;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (city_map[i][j] == 1) continue;
            if (i > 0) {
                down[i][j] = down[i-1][j];
                if (city_map[i-1][j] == 0 && j > 0)
                    down[i][j] = (down[i][j] + right[i-1][j])%MOD;
            }
            if (j > 0) {
                right[i][j] = right[i][j-1];
                if (city_map[i][j-1] == 0 && i > 0)
                    right[i][j] = (right[i][j] + down[i][j-1])%MOD;
            }
        }
    }

    answer = (right[m-1][n-1] + down[m-1][n-1])%MOD;
    return answer;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int> > mp(m, vector<int> (n, 0));
    for (int i=0; i<m; i++) for (int j=0; j<n; j++) cin >> mp[i][j];
    cout << solution(m, n, mp) << endl;
    return 0;
}

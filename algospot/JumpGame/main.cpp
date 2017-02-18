#include <iostream>
using namespace std;
#define MAX_LEN 200
int nums[MAX_LEN][MAX_LEN];
bool reach[MAX_LEN][MAX_LEN];
int main() {
    int C;
    int n;
    cin >> C;
    while (C--) {
        cin >> n;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cin >> nums[i][j];
                reach[i][j] = false;
            }
        }
        reach[0][0] = true;
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (reach[i][j]) {
                    reach[i][j+nums[i][j]] = true;
                    reach[i+nums[i][j]][j] = true;
                }
        if (reach[n-1][n-1])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

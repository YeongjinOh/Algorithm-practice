#include <iostream>
using namespace std;
#define MAX_LEN 100
int nums[MAX_LEN][MAX_LEN];
int cache[MAX_LEN][MAX_LEN];
int n;
bool jump(int i, int j) {
    if (i >= n || j >= n)
        return false;
    if (i == n-1 && j == n-1)
        return true;
    int &ret = cache[i][j];
    if (ret != -1)
        return ret;
    return ret = jump(i+nums[i][j],j) || jump(i,j+nums[i][j]);
}
int main() {
    int C;
    cin >> C;
    while (C--) {
        cin >> n;
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                cin >> nums[i][j];
        memset(cache,-1,sizeof(cache));
        if (jump(0,0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

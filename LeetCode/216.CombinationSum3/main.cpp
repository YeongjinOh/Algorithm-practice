#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int> > helper(int end, int k, int n) {
            vector<vector<int> > ret;
            if (k == 1) {
                if (end >= n && n >= 1) {
                    vector<int> ps;
                    ps.push_back(n);
                    ret.push_back(ps);
                }
                return ret;
            }
            for (int i=end; i>0; --i) {
                vector<vector<int> > tmp = helper(i-1, k-1, n-i);
                for (int j=0; j<tmp.size(); ++j) {
                    tmp[j].push_back(i);
                    ret.push_back(tmp[j]);
                }
            }
            return ret;
        }
        vector<vector<int> > combinationSum3(int k, int n) {
            return helper(9,k,n);
        }
};

int main(void) {
    Solution s;
    int a, b;
    cin >> a >> b;
    vector<vector<int> > res = s.combinationSum3(a,b);
    for (int i=0; i<res.size(); ++i) {
        for (int j=0; j<res[i].size(); ++j) {
            cout << res[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}

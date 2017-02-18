#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        void backtrack(vector<vector<int> > & ret, vector<int> & nums, int k, int n) {
            if (k==0) {
                if (n==0)
                    ret.push_back(nums);
                return;
            }
            int start = 1;
            if (nums.size() > 0)
                start = nums[nums.size()-1]+1;
            for (int i=start; i<=9; ++i) {
                nums.push_back(i);
                backtrack(ret, nums, k-1, n-i);
                nums.pop_back();
            }
        }
        vector<vector<int> > combinationSum3(int k, int n) {
            vector<vector<int> > ret;
            vector<int> nums;
            backtrack(ret, nums, k, n);
            return ret;
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

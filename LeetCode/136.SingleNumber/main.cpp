#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int res = 0;
            for (int i=0; i<nums.size(); ++i) {
                res ^= nums[i];
            }
            return res;
        }
};

int main() {
    int N;
    cin >> N;
    vector<int> nums;
    int num;
    Solution s;
    while (N--) {
        cin >> num;
        nums.push_back(num);
    }
    cout << s.singleNumber(nums) << endl;
}

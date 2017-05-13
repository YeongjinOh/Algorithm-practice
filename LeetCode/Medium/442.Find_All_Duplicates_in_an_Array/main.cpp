class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> dup;
        for (int i=0; i<nums.size(); i++) {
            int cur = abs(nums[i])-1;
            if (nums[cur] < 0) {
                dup.push_back(cur+1);
            } else {
                nums[cur] = -1*nums[cur];
            }
        }
        return dup;
    }
};

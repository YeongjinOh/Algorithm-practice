class Solution {
    public:
        void backtrack(vector<vector<int> > &res, vector<int> &cur, vector<int> &nums, int pos, int target) {
            if (target < 0 || pos == nums.size()) return;
            if (target == 0) {
                res.push_back(cur);
                return;
            }
            cur.push_back(nums[pos]);
            backtrack(res, cur, nums, pos, target-nums[pos]);
            cur.pop_back();
            backtrack(res, cur, nums, pos+1, target);
        }
        vector<vector<int>> combinationSum(vector<int>& nums, int target) {
            vector<vector<int> > res;
            vector<int> cur;
            backtrack(res, cur, nums, 0, target);
            return res;
        }
};

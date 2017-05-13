class Solution {
    public:

        bool backtrack(vector<int> len, vector<int> &nums, int pos) {
            if (pos == nums.size()) {
                for (int i =0; i<len.size(); i++) {
                    if (len[i] != 0) return false;
                }
                return true;
            }
            sort(len.begin(), len.end());
            for (int i=0; i<len.size(); i++) {
                if (len[i] >= nums[pos] && (i == 0 || len[i] != len[i-1])) {
                    len[i] -= nums[pos];
                    if (backtrack(len, nums, pos+1)) return true;
                    len[i] += nums[pos];
                }
            }
            return false;

        }

        bool makesquare(vector<int>& nums) {
            int sum = 0;
            for (int i=0; i<nums.size(); i++) sum += nums[i];
            if (sum % 4 != 0 || sum == 0) return false;
            vector<int> len(4,sum/4);
            sort(nums.begin(),nums.end());
            reverse(nums.begin(),nums.end());
            return backtrack(len,nums,0);
        }
};

class Solution {
    public:
        vector<int> singleNumber(vector<int>& nums) {
            vector<int> res = {0, 0};
            int diff = 0;
            for (int i=0; i<nums.size(); i++) diff ^= nums[i];
            // find the right most bit
            diff &= -diff;
            for (int i=0; i<nums.size(); i++) {
                if ((nums[i] & diff) == 0) {
                    res[0] ^= nums[i];
                } else {
                    res[1] ^= nums[i];
                }
            }
            return res;
        }
};

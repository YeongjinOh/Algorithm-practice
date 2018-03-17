class Solution {
    public:
        int minSubArrayLen(int s, vector<int>& nums) {
            int sum = 0, l=0, r=0, len=0;
            while(r<nums.size()) {
                sum += nums[r++];
                while (sum >= s) {
                    len = len==0?r-l:min(len, r-l);
                    sum -= nums[l++];
                }
            }
            return len;
        }
};

class Solution {
    public:
        int rob(vector<int>& nums) {
            int a=0, b=0, c=0;
            for (int i=0; i<nums.size(); i++) {
                c = a;
                a = b + nums[i];
                b = max(c,b);
            }
            return max(a,b);

        }
};

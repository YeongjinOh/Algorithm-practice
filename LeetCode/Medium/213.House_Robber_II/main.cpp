class Solution {
    public:

        int rob(vector<int>& nums) {
            int n = nums.size();
            if (n == 1) return nums[0];
            int use0=0, unuse0=0, tmp=0; // start from idx 0
            int use1=0, unuse1=0; // start from idx1
            for (int i=0; i<n; i++) {
                tmp = use0;
                use0 = unuse0 +  nums[i];
                unuse0 = max(tmp,unuse0);

                tmp = use1;
                if (i>0)
                    use1 = unuse1 +  nums[i];
                unuse1 = max(tmp,unuse1);
            }

            return max(unuse0,use1);
        }

};

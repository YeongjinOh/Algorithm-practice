class Solution {
    public:

        int gcd (int a, int b) {
            if (a<b) return gcd(b,a);
            if (a%b == 0) return b;
            return gcd(b, a%b);
        }

        void rotate(vector<int>& nums, int k) {
            int n = nums.size();
            if (n == 0) return;
            k = k%n;
            if (k <= 0) return;
            int c = gcd(n,k); // number of cycle
            for (int i=0; i<c; i++) {
                int start = nums[(i+k*n/c)%n];
                for (int j=n/c; j>1; j--) {
                    nums[ (i+k*j)%n] = nums[(i+k*(j-1))%n];
                }
                nums[i+k] = start;
            }
        }

        // another answer use reverse operations
        void rotate2(vector<int>& nums, int k) {
            if (k<=0) return;
            int n = nums.size();
            k = k%n;
            reverse(nums.begin(), nums.begin()+n-k);
            reverse(nums.begin()+n-k,nums.end());
            reverse(nums.begin(), nums.end());

        }
};

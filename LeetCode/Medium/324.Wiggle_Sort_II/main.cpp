class Solution {
    public:
        int findMedian(vector<int>& nums) {
            vector<int> cp = nums;
            sort(cp.begin(), cp.end());
            return cp[cp.size()/2];
        }
        // transfom index
        int getIndex(int i, int n) {
            int m = (n+1)/2;
            if (i < m) {
                return (m-1-i)*2;
            } else {
                return 2*(n-i)-1;
            }
        }
        void wiggleSort(vector<int>& nums) {
            int n = nums.size();
            if (n<=1) return;
            int median = findMedian(nums);
            int m = 0, r = 0, tmp;
            for (int i = 0; i<n; i++) {
                int cur = nums[getIndex(i, n)];
                if (cur == median) {
                    nums[getIndex(i,n)] = nums[getIndex(r,n)];
                    nums[getIndex(r,n)] = cur;
                    r++;
                } else if (cur < median) {
                    nums[getIndex(i,n)] = nums[getIndex(r,n)];
                    nums[getIndex(r,n)] = nums[getIndex(m,n)];
                    nums[getIndex(m,n)] = cur;
                    m++; r++;
                }
            }
        }
};

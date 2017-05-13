class Solution {
    public:
        struct Operator {
            bool greater;
            Operator(bool greater) : greater(greater) { }
            bool cmp (int a, int b) {
                if (greater) return a<b;
                return a>b;
            } ;
        };
        void heapify (vector<int> &nums, int here, int len, Operator opt) {
            while (2*here+1 < len) {
                int child = 2*here + 1;
                if (child + 1 < len && opt.cmp(nums[child],nums[child+1])) child++;
                if (!opt.cmp(nums[here],nums[child])) break;
                swap(nums[here], nums[child]);
                here = child;
            }
        }
        void buildHeap (vector<int> &nums, Operator opt) {
            for (int i=nums.size()/2; i>=0; i--) {
                heapify(nums, i, nums.size(), opt);
            }
        }
        void popHeap (vector<int> &nums, int len, Operator opt) {
            swap(nums[0], nums[--len]);
            heapify(nums, 0, len, opt);
        }

        int findKthLargest(vector<int>& nums, int k) {
            int n = nums.size();
            Operator opt(k < n/2);
            if (k >= n/2) {
                k = n+1-k;
            }
            buildHeap(nums, opt);
            for (int i=0; i<k-1; i++) popHeap(nums, n--, opt);
            return nums[0];
        }
};

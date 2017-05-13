class Solution {
    public:
        int kthSmallest(vector<vector<int>>& matrix, int k) {
            int n = matrix.size();
            int lo = matrix[0][0], hi = matrix[n-1][n-1];
            while (lo<hi) {
                int mid = (lo+hi)/2;
                int cnt = 0;
                for (int i=0; i<n; i++) {
                    cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                }
                if (cnt < k) lo = mid+1;
                else hi = mid;
            }
            return lo;
        }
};


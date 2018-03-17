class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int n = matrix.size();
            if (n == 0) return false;
            int m = matrix[0].size();
            int lo=0, hi = n*m-1;
            while (lo <= hi) {
                int mid = (lo+hi)/2;
                int r = mid/m, c = mid%m;
                if (matrix[r][c] == target) return true;
                if (matrix[r][c] > target) hi = mid-1;
                else lo = mid+1;
            }
            return false;
        }
};

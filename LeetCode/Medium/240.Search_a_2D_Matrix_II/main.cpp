class Solution {
    public:
        // Time: O(log(nm))
        // search in [i0,i1] x [j0,j1]
        bool search(vector<vector<int>>& matrix, int target, int i0, int j0, int i1, int j1) {
            if (i0 < 0 || j0 < 0 || i0 > i1 || j0 > j1) return false;
            if (i1-i0<4 && j1-j0<4) {
                for (int i=i0; i<=i1; i++) {
                    for (int j=j0; j<=j1; j++) {
                        if(matrix[i][j] == target) return true;
                    }
                }
                return false;
            }

            int mi = (i0+i1)/2, mj = (j0+j1)/2;
            if (matrix[mi][mj] == target) return true;

            if (matrix[mi][mj] < target)  // skip left top
                return search(matrix, target, mi+1, j0, i1, mj-1)
                    || search(matrix, target, i0, mj+1, mi-1, j1)
                    || search(matrix, target, mi, mj, i1, j1);
            return search(matrix, target, mi+1, j0, i1, mj-1)
                || search(matrix, target, i0, mj+1, mi-1, j1)
                || search(matrix, target, i0, j0, mi, mj);
        }
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int n = matrix.size();
            if (n == 0) return false;
            int m = matrix[0].size();
            return search(matrix, target, 0, 0, n-1, m-1);
        }

        // O(n+m)
        // Super better
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int n = matrix.size();
            if (n == 0) return false;
            int m = matrix[0].size();
            int i = 0, j = m-1;
            while (i < n && j >= 0) {
                int cur = matrix[i][j];
                if (cur == target) return true;
                if (cur < target) i++;
                else j--;
            }
            return false;
        }
};

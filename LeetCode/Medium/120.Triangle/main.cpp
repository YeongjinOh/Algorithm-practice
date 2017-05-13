class Solution {
    public:
        //////////////////////////////////////////////////////
        // Solution 1) DP
        // Time : O(n^2)
        // Extra space : O(n^2) (if we can't change triangle)
        //////////////////////////////////////////////////////
        int minimumTotal(vector<vector<int>>& triangle) {
            int n = triangle.size();
            if (n == 0) return 0;
            for (int i=n-2; i>=0; i--) {
                for (int j=0; j<triangle[i].size(); j++) {
                    triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
                }
            }
            return triangle[0][0];

        }

        //////////////////////////////////////////////////////
        // Solution 2) DP
        // Time : O(n^2)
        // Extra space : O(n)
        //////////////////////////////////////////////////////
        int minimumTotal2(vector<vector<int>>& triangle) {
            int n = triangle.size();
            if (n == 0) return 0;
            vector<int> minPath (n, 0);
            for (int i=n-1; i>=0; i--) {
                for (int j=0; j<triangle[i].size(); j++) {
                    minPath[j] = triangle[i][j] + min(minPath[j], minPath[j+1]);
                }
            }
            return minPath[0];
        }

};

class Solution {
public:
    bool isIndicesValid(int m, int n, int row, int col) {
        return 0 <= row && row < m && 0 <= col && col < n;
    }
    int dfs(const vector<vector<int> >& matrix, vector<vector<int> > &lip, int i, int j) {
        if (lip[i][j] != -1) return lip[i][j];
        int res = 1;
        int dr[] = {-1, 0, 1, 0}, dc[] = {0, -1, 0, 1};
        int m = matrix.size(), n = matrix[0].size();
        for (int d = 0; d < 4; d++) {
            int row = i+dr[d], col = j+dc[d];
            if (isIndicesValid(m, n, row, col) && matrix[i][j] < matrix[row][col]) {
                res = max(res, dfs(matrix, lip, row, col)+1);
            }
        }
        return lip[i][j] = res;
    }
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        int res = 0;
        vector<vector<int> > lip(m, vector<int> (n, -1));
        for (int i=0; i<m; i++) for (int j=0; j<n; j++) res = max(res, dfs(matrix, lip, i, j));
        return res;
    }
};

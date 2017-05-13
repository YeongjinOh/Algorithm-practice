class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int> > res(n, vector<int>(n));
            int cur = 1, row = 0, col = 0;
            int rowDir[4] = {0, 1, 0, -1}, colDir[4] = {1, 0, -1, 0};
            for (int layer = n-1; layer > 0; layer-=2) {
                for (int d=0; d<4; d++) {
                    for (int i=0; i<layer; i++) {
                        res[row][col] = cur++;
                        row += rowDir[d];
                        col += colDir[d];
                    }
                }
                row++; col++;
            }
            if (n%2 == 1) res[row][col] = cur;
            return res;
        }
};

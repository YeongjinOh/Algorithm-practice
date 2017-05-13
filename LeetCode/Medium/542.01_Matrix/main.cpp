class Solution {
    public:
        bool checkRange(int i, int j, int n, int m) {
            return 0<=i && i<n && 0<=j && j<m;
        }
        vector<vector<int> > updateMatrix(vector<vector<int> >& matrix) {
            int n = matrix.size(), m = matrix[0].size();
            int rowDiff[4] = {1,-1,0,0}, colDiff[4] = {0,0,-1,1};
            vector<vector<int> > res(n, vector<int> (m, 0));
            vector<vector<bool> > visit(n, vector<bool> (m, false));
            queue<pair<int,int> > q;
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    if (matrix[i][j] == 0) {
                        visit[i][j] = true;
                        q.push(make_pair(i,j));
                    }
                }
            }
            int dist = 0;
            while (!q.empty()) {

                for (int i=0, sz=q.size(); i<sz; i++) {
                    int row = q.front().first, col = q.front().second;

                    q.pop();
                    res[row][col] = dist;
                    for (int j=0; j<4; j++) {
                        int r = row+rowDiff[j], c = col+colDiff[j];

                        if (checkRange(r,c,n,m) && !visit[r][c]) {
                            q.push(make_pair(r,c));
                            visit[r][c] = true;
                        }
                    }

                }
                dist++;
            }
            return res;
        }
};

class Solution {
    public:
        int leastBricks(vector<vector<int>>& wall) {
            int rows = wall.size();
            vector<int> verticalPath;
            for (int i=0; i<rows; i++) verticalPath.push_back(wall[i][0]);
            for (int i=0; i<rows; i++) {
                for (int j=1; j<wall[i].size(); j++) {
                    wall[i][j] += wall[i][j-1];
                    verticalPath.push_back(wall[i][j]);
                }
            }
            sort(verticalPath.begin(), verticalPath.end());
            int width = verticalPath.back();
            int maxCnt = 0, cur = 0, cnt = 0;
            for (int i=0; i<verticalPath.size() && verticalPath[i] < width; i++) {
                if (cur == verticalPath[i]) {
                    cnt++;
                    maxCnt = max(maxCnt, cnt);
                } else {
                    cur = verticalPath[i];
                    cnt = 1;
                    maxCnt = max(maxCnt, cnt);
                }
            }
            return rows-maxCnt;
        }
};

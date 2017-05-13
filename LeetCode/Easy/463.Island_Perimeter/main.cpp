class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // check exceptional case
		int height = grid.size();
        if (height == 0) return 0;
        int width = grid[0].size();

		// calc sum
        int sum = 0;
        for (int i=0; i<height; i++) {
            for (int j=0; j<width; j++) {
                if (grid[i][j]) {
                    int add = 4;
					// if add repeated
                    if (i+1<height && grid[i+1][j]) add-=2;
                    if (j+1<width && grid[i][j+1]) add-=2;
                    sum += add;
                }
            }
        }
        return sum;
    }
};

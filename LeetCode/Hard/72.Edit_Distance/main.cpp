class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int> > cache (n+1, vector<int> (m+1, 0));
        for (int i=0; i<m; ++i) cache[n][i] = m-i;
        for (int i=0; i<n; ++i) cache[i][m] = n-i;
        for (int i=n-1; i>=0; i--) {
            for (int j=m-1; j>=0; j--) {
                if (word1[i] == word2[j]) {
                    cache[i][j] = cache[i+1][j+1];
                } else {
                    cache[i][j] = min(min(cache[i][j+1], cache[i+1][j+1]), cache[i+1][j]) + 1; // insertion, replace, deletion
                }
            }
        }
        return cache[0][0];
    }
};

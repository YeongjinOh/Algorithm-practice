class Solution {
    public:
        int superPow(int a, vector<int>& b) {
            const int MOD = 1337;
            a = a%MOD;
            int cache[11][MOD];
            for (int j=0; j<MOD; j++) {
                cache[0][j] = 1;
                for (int i=1; i<=10; i++) {
                    cache[i][j] = (cache[i-1][j]*j)%MOD;
                }
            }
            int res = 1;
            for (int i=0; i<b.size(); i++) {
                res = (cache[10][res] * cache[b[i]][a]) % MOD;
            }
            return res;
        }
};

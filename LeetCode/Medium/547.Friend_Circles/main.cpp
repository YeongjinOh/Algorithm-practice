class Solution {
    public:

        struct DisjointSet {
            vector<int> parents, rank;
            DisjointSet(int num) : parents(num), rank(num,1) {
                for (int i=0; i<num; i++)
                    parents[i] = i;
            }
            int find(int here) {
                if (here == parents[here]) return here;
                return parents[here] = find(parents[here]);
            }
            void Union (int a, int b) {
                a = find(a);
                b = find(b);
                if (a == b)
                    return;
                if (rank[a] > rank[b]) {
                    parents[b] = a;
                    rank[a] += rank[b];
                } else {
                    parents[a] = b;
                    rank[b] += rank[a];
                }

            }
            int countRoot () {
                int cnt = 0;
                for (int i=0; i<parents.size(); i++)
                    if(parents[i] == i)
                        cnt++;
                return cnt;
            }
        };

        int findCircleNum(vector<vector<int>>& M) {
            int n = M.size();
            if (n == 0) return 0;
            if (M[0].size() != n) return -1;
            DisjointSet ds(n);
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (M[i][j])
                        ds.Union(i,j);
                }
            }
            return ds.countRoot();
        }
};

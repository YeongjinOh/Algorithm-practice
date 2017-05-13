class Solution {
    public:
        //////////////////////////////////////////////////////////
        // Solution 1) use memoization and top-down approach
        //////////////////////////////////////////////////////////
        int count (unordered_map<long long,int> &cache, long long n) {
            if (cache.find(n) != cache.end()) return cache[n];
            if (n%2 == 0) return cache[n] = count(cache,n/2) + 1;
            return cache[n] = min(count(cache,n-1), count(cache,n+1)) + 1;
        }
        int integerReplacement(int n) {
            unordered_map<long long, int> cache;
            cache[1] = 0;
            return count(cache, n);
        }

        //////////////////////////////////////////////////////////
        // Solution 2) simple iteration
        //////////////////////////////////////////////////////////
        int integerReplacement2(int n) {
            int res = 0;
            while (n > 1) {
                if (n%2 == 0) {
                    n/=2;
                } else if (n%4 == 3 && n != 3) {
                    n/=2; // to avoid overflow
                    n++;
                    res++;
                } else {
                    n--;
                }
                res++;
            }
            return res;
        }

};


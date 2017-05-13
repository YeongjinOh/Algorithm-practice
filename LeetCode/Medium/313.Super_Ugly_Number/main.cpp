class Solution {
    public:

        int nthSuperUglyNumber(int n, vector<int>& primes) {
            priority_queue<pair<int,int> > pq;  //min Heap by (num,idx of prime)
            int k = primes.size();
            vector<int> ptr(k,0);
            vector<int> res;
            res.push_back(1);
            for (int i=0; i<k; i++) {
                pq.push(make_pair(-primes[i],i));
            }
            while (res.size() < n) {
                int num = -pq.top().first, idx = pq.top().second;
                pq.pop();
                ptr[idx]++;
                if (num > res.back())
                    res.push_back(num);
                pq.push(make_pair(-1*res[ptr[idx]]*primes[idx],idx));
            }
            return res.back();
        }

};

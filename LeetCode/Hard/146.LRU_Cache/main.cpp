/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

// 이 경우에는 dq에 n개 이상의 element가 들어갈 수 있으므로..안됨
class LRUCache {
    public:
        int n;
        LRUCache(int capacity) : n(capacity) { }

        unordered_map<int,int> hash, cnt;
        deque<int> dq;

        int get(int key) {
            if (hash.find(key) == hash.end())
                return -1;
            dq.push_back(key);
            cnt[key]++;
            return hash[key];
        }

        void put(int key, int value) {
            if (cnt[key] == 0 && hash.size() == n) {
                while (!dq.empty() && --cnt[dq.front()] > 0) { dq.pop_front(); }
                hash.erase(dq.front());
                dq.pop_front();
            }
            dq.push_back(key);
            cnt[key]++;
            hash[key] = value;
        }
};

// 그래서 list가 필요하다.
// 뒤에거 보다 좀더 깔끔한 코드.
class LRUCache2 {
    public:
        int n;
        LRUCache(int capacity) : n(capacity) { }

        unordered_map<int,int> hash;
        unordered_map<int, list<int>::iterator> iters;
        list<int> order;

        int get(int key) {
            if (hash.find(key) == hash.end())
                return -1;
            order.erase(iters[key]);
            order.push_back(key);
            iters[key] = --(order.end());
            return hash[key];
        }

        void put(int key, int value) {
            if (hash.find(key) == hash.end()) {
                if (hash.size() == n) {
                    hash.erase(order.front());
                    iters.erase(order.front());
                    order.pop_front();
                }
            } else {
                order.erase(iters[key]);
            }
            order.push_back(key);
            iters[key] = --(order.end());
            hash[key] = value;
        }
};

class LRUCache3 {
    public:
        int n;
        list<int> order;
        unordered_map<int, pair<int, list<int>::iterator> > mp;
        LRUCache(int capacity) : n(capacity) { }

        void refresh(int key) {
            if (mp.find(key) != mp.end()) {
                order.erase(mp[key].second);
            }
            if (order.size() == n) {
                order.erase(order.begin());
            }
            order.push_back(key);
        }

        int get(int key) {
            if (mp.find(key) == mp.end()) return -1;
            refresh(key);
            mp[key].second = --(order.end());
            return mp[key].first;
        }

        void put(int key, int value) {
            if (order.size() == n) {
                if (mp.find(key) == mp.end())
                    mp.erase(order.front());
            }
            refresh(key);
            mp[key] = make_pair(value, --(order.end()));
        }
};


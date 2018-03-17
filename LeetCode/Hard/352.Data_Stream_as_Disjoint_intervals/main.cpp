#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {
public:
   /** Initialize your data structure here. */
        
        map<int, int> ltree, rtree;
        vector<Interval> res;
        bool changed = false;
        SummaryRanges() { }

        void addNum(int val) {
            bool lm = false;
            auto lb = ltree.lower_bound(val);
            if (lb != ltree.end()) {
                if (lb->first == val) return;
                if (lb->first == val+1) {
                    lm = true;
                }
            }
            auto rb = rtree.lower_bound(val-1);
            bool rm = false;
            if (rb != rtree.end()) {
                if (rb->first == val-1) {
                    rm = true;
                } else if (rb->second <= val) return;
            }
            changed = true;

            if (lm && rm) {
                // merge both side -> [ll, rr]
                int ll = rb->second, rr = lb->second;
                auto it = ltree.lower_bound(ll);
                it->second = rr;
                ltree.erase(lb);
                it = rtree.lower_bound(rr);
                it->second = ll;
                rtree.erase(rb);
            } else if (lm) {
                int rr = lb->second;
                ltree[val] = lb->second;
                ltree.erase(lb);
                auto it = rtree.lower_bound(rr);
                it->second = val;
            } else if (rm) {
                int ll = rb->second;
                auto it = ltree.lower_bound(ll);
                it->second = val;
                rtree[val] = rb->second;
                rtree.erase(rb);
            } else {
                ltree[val] = val;
                rtree[val] = val;
            }
        }

        vector<Interval> getIntervals() {
            if (!changed) return res;
            res.clear();
            for (auto it = ltree.begin(); it != ltree.end(); it++) {
                res.push_back(Interval(it->first,it->second));
                // printf("[%d,%d] ", it->first, it->second);
            }
            changed = false;
            // cout << endl;
            return res;
        }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */


int main() {
    SummaryRanges sr;
    while(true) {
        int val; cin >> val;
        sr.addNum(val);
        sr.getIntervals();
    }
}

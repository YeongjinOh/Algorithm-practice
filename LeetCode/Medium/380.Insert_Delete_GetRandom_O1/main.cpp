class RandomizedSet {
    unordered_map<int, int> mp;
    vector<int> items;
    public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mp.find(val) != mp.end())
            return false;
        mp[val] = items.size();
        items.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mp.find(val) == mp.end())
            return false;
        int idx = mp[val];
        items[idx] = items.back();
        items.pop_back();
        mp[items[idx]] = idx;
        mp.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int k = items.size();
        if (k==0) return -1;
        return items[rand()%k];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */


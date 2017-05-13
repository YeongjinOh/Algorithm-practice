class Solution {
    vector<int> origin;
    vector<int> tmp;
    int size;
    public:
    Solution(vector<int> nums) {
        origin = tmp = nums;
        size = nums.size();
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return tmp = origin;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i=0; i<size; i++){
            int idx = rand();
            swap(tmp[i%size], tmp[idx%size]);
        }
        return tmp;
    }
};




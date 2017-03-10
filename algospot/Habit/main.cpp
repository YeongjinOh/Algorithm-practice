#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int C, k;
string str;

struct Comparator {
    ////////////////////////////////////////////////
    // important
    // vector<int> group;
    // should use reference for performance!!
    // /////////////////////////////////////////////
    vector<int> &group;
    int t;
    Comparator (vector<int>& group, int t) : group(group), t(t) { }
    bool operator () (int a, int b) {
        if (group[a] == group[b])
            return group[a+t] < group[b+t];
        return group[a] < group[b];
    }
};

// implement manber-myers algorithm to build suffix array in O(n * log^2 n)
vector<int> getSuffixArray (string & str) {

    vector<int> suffix, group;
    for (int i=0; i<str.size(); i++) {
        suffix.push_back(i);
        group.push_back(str[i]);
    }
    group.push_back(-1);
    int t = 1, n = str.size();
    while (t < n) {
        Comparator cmp(group, t);
        sort(suffix.begin(), suffix.end(), cmp);
        t *= 2;

        vector<int> newGroup(n+1);
        newGroup[n] = -1;
        newGroup[suffix[0]] = 0;
        for (int i=1; i<n; i++) {
            if (cmp(suffix[i-1], suffix[i]))
                newGroup[suffix[i]] = newGroup[suffix[i-1]] + 1;
            else
                newGroup[suffix[i]] = newGroup[suffix[i-1]];
        }
        group = newGroup;
    }
    return suffix;
}

int main() {
    cin >> C;
    while (C--) {
        cin >> k >> str;
        int n = str.size();
        vector<int> suffix = getSuffixArray (str);
        int len = 0;
        for (int i=0; i+k <= n; i++) {
            int j = 0;
            // n-suffix[i] means i-th suffix's length
            while (suffix[i]+j <n && suffix[i+k-1]+j < n && str[suffix[i]+j] == str[suffix[i+k-1]+j]) {
                j++;
            }
            len = max<int>(len, j);
        }
        cout << len << endl;
    }
}

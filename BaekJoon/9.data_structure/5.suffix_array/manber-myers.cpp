#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

// this code implement manber-myers algorithm to build suffix array
// it takes O(n * log^2 n)

struct Comparator {
    vector<int> group;
    int t;
    Comparator(vector<int> & g, int t) : group(g), t(t) { }
    bool operator() (int a, int b) {
        if (group[a] == group[b])
            return group[a+t] < group[b+t];
        return group[a] < group[b];
    }
};
int main() {
    string str;
    cin >> str;
    int n = str.size();
    vector<int> suffix, group;
    for (int i=0; i<n; i++) {
        suffix.push_back(i);
        group.push_back(str[i]);
    }
    group.push_back(-1);
    int t = 1;
    while (t < n) {
        Comparator cmp(group, t);
        sort(suffix.begin(), suffix.end(), cmp);
        t *= 2;
        if (t >= n) break;

        vector<int> newGroup(n+1);
        newGroup[n] = -1;
        for (int i=1; i<n; i++) {
            if (cmp(suffix[i-1], suffix[i]))
                newGroup[suffix[i]] = newGroup[suffix[i-1]]+1;
            else
                newGroup[suffix[i]] = newGroup[suffix[i-1]];
        group = newGroup;
        }
    }
    for (int i=0; i<suffix.size(); i++) {
        cout << str.substr(suffix[i]) << endl;
    }
    return 0;
}

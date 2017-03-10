#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

// this code implement the easiest way to build suffix array
// it takes O(n^2 * log n)

struct Comparator {
    string s;
    Comparator(string s) : s(s) { }
    bool operator() (int a, int b) {
        return s.substr(a) < s.substr(b);
    }
};
int main() {
    string str;
    cin >> str;

    vector<int> suffix;
    for (int i=0; i<str.size(); i++)
        suffix.push_back(i);
    sort(suffix.begin(), suffix.end(), Comparator(str));
    for (int i=0; i<suffix.size(); i++) {
        cout << str.substr(suffix[i]) << endl;
    }
    return 0;
}

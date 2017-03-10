#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 100005
using namespace std;
int C;
int kmp[MAX];
string str;
char key (int idx) {
    return str[str.size()-1-idx];
}
int main() {
    cin >> C;
    while (C--) {
        cin >> str;
        int len = str.size();
        // build partial matching
        memset(kmp, 0, sizeof(kmp));
        int i=1, j=0;
        while (i+j < len) {
            if (key(i+j) == key(j)) {
                kmp[i+j] = j+1;
                j++;
            } else if (j == 0) {
                i++;
            } else {
                i += j - kmp[j-1];
                j = kmp[j-1];
            }
        }

        i=0; j=0;
        while (i+j < len) {
            if (str[i+j] == key(j)) j++;
            else if (j == 0) i++;
            else {
                i += j - kmp[j-1];
                j = kmp[j-1];
            }
        }
        cout << 2*len - j << endl;
    }
}

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
#define MAX 400001

int kmp[MAX];
char str[MAX];
int main() {
    gets(str); gets(str+strlen(str));
    int len = strlen(str);

    // build partial match maximum length
    int i=1, j=0;
    memset(kmp, 0, sizeof(kmp));
    while(i+j < len) {
        if (str[i+j] == str[j]) {
            kmp[i+j] = j+1;
            j++;
        } else if (j == 0) {
            i++;
        } else {
            i += j - kmp[j-1];
            j = kmp[j-1];
        }
    }

    vector<int> ret;
    while (len > 0) {
        ret.push_back(len);
        len = kmp[len-1];
    }
    for (int i=ret.size()-1; i>=0; i--)
        cout << ret[i] << " ";
    cout << endl;
}

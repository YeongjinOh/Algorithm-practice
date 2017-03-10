#include <iostream>
#include <cstring>

using namespace std;

int kmp[51];
int main () {
    char str[2501], key[51];
    int strLen = 0, keyLen = 0;
    while(true) {
        scanf("%c",&str[strLen]);
        if (str[strLen] == '\n') break;
        strLen++;
    }
    while(true) {
        scanf("%c",&key[keyLen]);
        if (key[keyLen] == '\n') break;
        keyLen++;
    }
    // i = end of substr = len(substr)-1
    for (int i=0; i<keyLen; i++) {

        // k = len(substr) - len(prefix) = i+1 - len(prefix)
        for (int k=1; k<=i; k++) {
            bool match = true;
            for (int j=0; j<=i-k; j++) {
                if (key[j] != key[j+k]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                // len(prefix)
                kmp[i] = (i+1)-k;
                break;
            }
        }
    }
    int cnt = 0, i = 0, j = 0;
    while(i + keyLen <= strLen) {
        bool match = true;
        for (; j<keyLen; j++) {
            if (str[i+j] != key[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            i += keyLen;
            j = 0;
            cnt++;
        } else if (j==0) {
            i++;
        } else {
            i += j - kmp[j-1];
            j = kmp[j-1];
        }
    }
    cout << cnt << endl;
    return 0;
}

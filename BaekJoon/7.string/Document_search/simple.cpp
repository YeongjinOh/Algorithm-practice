#include <iostream>
#include <cstring>
#define MAX 2501

using namespace std;

int kmp[MAX];
int main () {
    char str[MAX], key[51];
    int strLen = 0;
    while(true) {
        scanf("%c", &str[strLen]);
        if (str[strLen] == '\n') break;
        strLen++;
    }
    int keyLen = 0;
    while(true) {
        scanf("%c", &key[keyLen]);
        if (key[keyLen] == '\n') break;
        keyLen++;
    }

    int cnt = 0;
    int i=0;
    while (i + keyLen <= strLen) {
        bool match = true;
        for (int j=0; j<keyLen; j++)
            if (str[i+j] != key[j]) {
                match = false;
                break;
            }
        if (match) {
            cnt++;
            i += keyLen;
        } else {
            i++;
        }
    }
    cout << cnt << endl;
    return 0;
}

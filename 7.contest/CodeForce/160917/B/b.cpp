#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_LEN 50001
char word[MAX_LEN];
int num[26];

int stlen (char * arr) {
    int res = 0;
    while (arr[res] != '\0') {
        res++;
    }
    return res;
}

bool check() {
    for (int i=0; i<26; i++)
        if (num[i]>1)
            return false;
    return true;
}
void print(int i) {
    if (word[i] == '?') {
        printf("A");
        return;
    }
    printf("%c",word[i]);
}
void printSolution(int cur, int len) {

    for (int i=0; i<cur-26; i++) {
        print(i);
    }
    int j=0;
    for (int i=cur-26; i<cur; i++) {
        if (word[i] == '?') {
            while(num[j] != 0) {
                j++;
            }
            num[j] = 1;
            printf("%c",'A'+j);
        } else {
            printf("%c", word[i]);
        }
    }
    for (int i=cur; i<len; i++) {
        print(i);
    }
    printf("\n");
}

int main () {
    scanf("%s",word);
    int len = stlen(word);

    if (len<26) {
        printf("-1\n");
        return 0;
    }

    // initialize num
    for (int i=0; i<26; i++)
        num[i] = 0;

    int cur;
    for (cur=0; cur<26; cur++) {
        if (word[cur] != '?')
            num[word[cur]-'A']++;
    }

    if (check()) {
        // do
        printSolution(cur, len);
        return 0;
    }

    while(cur<len) {
        if (word[cur] != '?')
            num[word[cur]-'A']++;
        if (word[cur-26] != '?')
            num[word[cur-26]-'A']--;
        cur++;
        if (check()) {
            printSolution(cur, len);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}

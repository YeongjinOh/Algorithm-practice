#include <cstdio>
#include <iostream>
using namespace std;
int tree[1024*1024];
int stlen (char * arr) {
    int res = 0;
    while (arr[res] != '\0') {
        res++;
    }
    return res;
}
int main () {
    int n;
    scanf("%d", &n);
    char sym, dum;
    scanf("%c",&dum);
    char query[30];
    for (int i=0; i<n; i++) {
        fgets(query, sizeof query, stdin);
        int len = stlen(query)-3;
        int cur, idx;
        switch (query[0]) {
            case '+':
                cur = 2;
                idx = 0;
                while (cur <= len+1) {
                    idx *= 2;
                    idx += (query[cur]-'0')%2;
                    cur++;
                }
                tree[idx]++;
                break;
            case '-':
                cur = 2;
                idx = 0;
                while (cur <= len+1) {
                    idx *= 2;
                    idx += (query[cur]-'0')%2;
                    cur++;
                }
                tree[idx]--;
                break;
            case '?':
                cur = 2;
                idx = 0;
                while(cur <= len+1) {
                    idx *= 2;
                    idx += query[cur]-'0';
                    cur++;
                }
                printf("%d\n",tree[idx]);
                break;
        }
    }

    return 0;
}

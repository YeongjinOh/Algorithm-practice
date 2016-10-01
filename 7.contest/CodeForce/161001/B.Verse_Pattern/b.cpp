#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int syl[100];

int main () {
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&syl[i]);
    }
    char ch;
    bool flag = true;
    scanf("%c",&ch);
    for (int i=0; i<n; i++) {
        int cnt=0;
        scanf("%c",&ch);
        while(ch != '\n') {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y')
                cnt++;
            scanf("%c",&ch);
        }
        if (syl[i] != cnt) {
            flag = false;
       }
    }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}

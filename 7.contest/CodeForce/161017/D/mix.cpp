#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int n, m;

/** related to days **/
int d[100005]; // possible subject for i-th day

/** related to subjects **/
int a[100005]; // necessary days to prepare exam for i-th subject
int idx[100005]; // current cadidate exam day for i-th subject
int used[100005];
int pday, day, last; //previous, current, last day
int sub; // current subject

int main () {

    //read input
    scanf("%d%d", &n, &m);

    for (int i=1; i<=n; i++) {
        scanf("%d",&d[i]);
    }
    for (int i=1; i<=m; i++)
        scanf("%d",&a[i]);

    int l=0, r=n+1, cur=0;
    while (l<r) {
        cur++;
        int mm = (l+r)/2;
        int num = 0;
        for (int i=mm; i>0; i--) {
            if (d[i] != 0 && used[d[i]] != cur) {
                used[d[i]] = cur;
                idx[d[i]] = i;
                num++;
            }
        }
        set<int> mySet (idx+1, idx+m+1);
        bool check = true;
        if (num != m)
            check = false;
        int rest = 0, pday = 0;
        for (set<int>::iterator iter = mySet.begin(); check && iter != mySet.end(); ++iter) {
            int day = *iter;
            int sub = d[day];
            rest += day - pday - 1;
            if (a[sub] > rest) {
                check = false;
            } else {
                rest -= a[sub];
                pday = day;
            }
        }
        if (check) {
            r = mm;
        } else {
            l = mm+1;
        }
    }
    if (l > n)
        l = -1;
    printf("%d\n", l);
    return 0;
}

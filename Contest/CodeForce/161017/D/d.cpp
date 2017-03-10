#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int n, m;

/*******************************************************************
틀린 이유 :
days : 0 0 1 2 1 3 0 2 0 1 2
와 같이 들어 올 때, day indicator가
[3, 4, 6] -> [3, 8, 6]
즉 그 다음거(2)를 기준으로 바꿨었는데,
[5, 4, 6] 일 때 될 수도 있다.

따라서, 마지막 indicator last에 대하여, 나머지 indicator는
그subject의 exam day중 가장 뒤 값을 취해야 한다.
*******************************************************************/


/** related to days **/
int d[100005]; // possible subject for i-th day

/** related to subjects **/
int a[100005]; // necessary days to prepare exam for i-th subject
int idx[100005]; // current cadidate exam day for i-th subject
set<int> mySet; // sorted indices for candidate day
int pday, day, last; //previous, current, last day
int sub; // current subject

int main () {

    //read input
    scanf("%d%d", &n, &m);

    for (int i=1; i<=n; i++) {
        scanf("%d",&d[i]);
        if (d[i] != 0 && idx[d[i]] == 0) {
            idx[d[i]] = i;
            mySet.insert(i);
        }
    }
    for (int i=1; i<=m; i++)
        scanf("%d",&a[i]);

    bool check = false;
    int last =  *(--mySet.end());
    while (!check && last <= n) {
        int rest = 0;
        check = true;
        pday = 0;
        for (set<int>::iterator iter = mySet.begin(); iter!=mySet.end(); ++iter) {
            int day = *iter;
            int sub = d[day];
            rest += day - pday - 1;
            if (a[sub] > rest) {
                check = false;
                last++;
                while(d[last] == 0) {last++;}
                sub = d[last];
                mySet.erase(idx[sub]);
                mySet.insert(last);
                idx[sub] = last;
                break;
            } else {
                rest -= a[sub];
                pday = day;
            }
        }
    }
    if (last > n)
        printf("-1\n");
    else
        printf("%d\n", last);
    return 0;
}

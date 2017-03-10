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

/*******************************************************
1. last의 최소값을 찾는 것 이므로, binary try
2. 각각의 last에 대해, 뒤에서부터 앞으로 읽으면서 각 subject의 마지막 exam day만을 고려
3. exception 처리 : 빠진 subject가 있는지 체크하기 위해 카운트(v)
4. 계산 : 뒤에서 앞으로가면서 그냥 한번에 계산. res를 +a만큼 하거나 -1만큼 하거나.
    res가 0보다 작아지는 경우도 괜찮. 마지막 순간(젤 앞으로 왔을 때) 0이면 됨.
 *******************************************************/

int main () {

    //read input
    scanf("%d%d", &n, &m);

    for (int i=1; i<=n; i++) {
        scanf("%d",&d[i]);
    }
    for (int i=1; i<=m; i++)
        scanf("%d",&a[i]);

    int l=m, r=n+1, cur=0;
    while (l<r) {
        int mm = (l+r)/2;
        int res = 0, v = 0;
        cur++;
        for (int i=mm; i>0; i--) {
            if (used[d[i]] != cur && d[i]) {
                used[d[i]] = cur;
                v++;
                res+=a[d[i]];
            } else
                res = max(res-1,0);
        }
        if (v<m || res>0)
            l = mm + 1;
        else
            r = mm;
    }
    if (l == n+1)
        l = -1;

    printf("%d\n", l);
    return 0;
}

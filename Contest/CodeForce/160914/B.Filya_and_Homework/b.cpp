#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];

void yes() {printf("YES\n");}
void no() {printf("NO\n");}
int main () {
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    int min = arr[0], max = arr[n-1];
    if (min == max) {
        yes();
        return 0;
    }

    int  i=0;
    while(min == arr[i] && i<n) { i++; }
    int diff_from_left = arr[i];
    i=n-1;
    while(max == arr[i] && i>=0) { i--; }
    int diff_from_right = arr[i];

    if (diff_from_left == max || diff_from_right == min) {
        yes();
    } else if (diff_from_left == diff_from_right) {
        if (max-diff_from_left == diff_from_left-min)
            yes();
        else
            no();
    } else {
        no();
    }
    return 0;
}

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define LEN 100
int enemy[LEN], we[LEN];

using namespace std;
int C, n;

int main() {
    cin >> C;
    while (C--) {
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> enemy[i];
        for (int i=0; i<n; i++)
            cin >> we[i];
        sort(enemy,enemy+n);
        sort(we,we+n);
        int i=n-1, j=n-1;
        int cnt = 0;
        while(j>=0) {
            while(i>=0 && enemy[i] > we[j]) {i--;}
            if(i < 0) break;
            cnt++;
            i--;
            j--;
        }
        cout << cnt << endl;
    }
}

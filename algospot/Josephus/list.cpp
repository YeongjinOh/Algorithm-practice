#include <iostream>
#include <cstring>
#include <list>
#include <algorithm>

using namespace std;
int C;

int main() {
    cin >> C;
    while (C--) {
        int n, k;
        cin >> n >> k;
        list<int> nums;
        for (int i=1; i<=n; ++i)
            nums.push_back(i);

        list<int>::iterator kill = nums.begin();
        for (int i=0; i<n-2; i++) {
            kill = nums.erase(kill);
            if (kill == nums.end()) kill = nums.begin();
            for (int j=0; j<k-1; j++) {
                kill++;
                if (kill == nums.end()) kill = nums.begin();
            }
        }
        int a = *nums.begin(), b = *(++nums.begin());
        printf("%d %d\n", min<int>(a, b), max<int>(a, b));
    }
}

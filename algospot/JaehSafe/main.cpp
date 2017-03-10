#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

int C;
#define MAX 10005

int kmp[MAX];
int len;
char left[MAX], right[MAX];

void buildKmp () {
    // build kmp
    int begin = 1, matched = 0;
    while (begin + matched < len) {
        if (right[begin + matched] == right[matched]) {
            kmp[begin + matched] = matched + 1;
            matched++;
        } else if (matched == 0) {
            begin++;
        } else {
            begin += matched - kmp[matched-1];
            matched = kmp[matched-1];
        }
    }
}

// left, right 를 비교하는 방식
// left : aaabba
// right:   abbaaa
// -> tick = 2;
// input 순서 : right -> left -> right -> ...
int main() {
    std::cin >> C;
    while (C--) {
        int n;
        std::cin >> n;
        scanf("%s",right);
        len = strlen(right);
        buildKmp();
        int res = 0;
        // n이 짝수, 홀수마다 cur, next, direction을 바꿔준다
        for (int i=0; i<n; i++) {
            // 짝수 번째(i)의 next는 left
            if (i%2 == 0)
                scanf("%s",left);
            else {
                scanf("%s",right);
                buildKmp();
            }
            int matched = 0, tick = 0;
            while(matched < len) {
                // left는 Module len 연산을 써서 연장시킨다.
                if (left[(matched+tick)%len] == right[matched]) matched++;
                else if (matched == 0) tick++;
                else {
                    tick += matched - kmp[matched-1];
                    matched = kmp[matched-1];
                }
            }
            res += tick;
        }
        std::cout << res << std::endl;
    }
}

// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <cstdio>
#include <iostream>
using namespace std;
// x1 <= x2 and y1 <= y2
int line[100][4];
bool vert[100]; // true if x same
// rect[i] means (x1, y1), (x2, y2) of i-th rectangles
// x1 <= x2 and y1 <= y2
int rect[100][4];
int temp[100][4];

int abs (int a) {
    return a>0?a:-a;
}

void setRect (int idx, int x1, int y1, int x2, int y2) {
    rect[idx][0] = x1;
    rect[idx][1] = y1;
    rect[idx][2] = x2;
    rect[idx][3] = y2;
}

void setTemp (int idx, int x1, int y1, int x2, int y2) {
    temp[idx][0] = x1;
    temp[idx][1] = y1;
    temp[idx][2] = x2;
    temp[idx][3] = y2;
}

void moveTempToRect(int num) {
    for (int i=0; i<num; i++)
        for (int j=0; j<4; j++)
            rect[i][j] = temp[i][j];
}

// check if line consists of one union rectangle
bool checkUnion (int idx, int k) {
    if (vert[idx])
        return abs(line[idx][1]-line[idx][3]) <= 2*k;
    else
        return abs(line[idx][0]-line[idx][2]) <= 2*k;
}

bool check (int n, int k) {
    int num=0;
    // initialize
    if (checkUnion (0, k)) {
        num = 1;
        setRect(0, line[0][0]-k, line[0][1]-k, line[0][2]+k, line[0][3]+k);
    } else {
        num = 2;
        setRect(0, line[0][0]-k, line[0][1]-k, line[0][0]+k, line[0][1]+k);
        setRect(1, line[0][2]-k, line[0][3]-k, line[0][2]+k, line[0][3]+k);
    }
    // check intersection is not empty
    for (int i=1; i<n; i++) {
        // union if one rect
        int next_num=0;
        if (checkUnion(i,k)) {
            int x1, y1, x2, y2, l, r, t, d;
            x1 = line[i][0]-k;
            y1 = line[i][1]-k;
            x2 = line[i][2]+k;
            y2 = line[i][3]+k;

            for (int j=0; j<num; j++) {
                l = x1 > rect[j][0] ? x1 : rect[j][0];
                t = y1 > rect[j][1] ? y1 : rect[j][1];
                r = x2 < rect[j][2] ? x2 : rect[j][2];
                d = y2 < rect[j][3] ? y2 : rect[j][3];
                // if no intersection
                if (l > r || t > d)
                    continue;
                setTemp(next_num, l, t, r, d);
                next_num++;
            }
            if (next_num == 0)
                return false;
            num = next_num;
            moveTempToRect(num);
        } else {
            int x11, y11, x12, y12, l1, r1, t1, d1;
            x11 = line[i][0]-k;
            y11 = line[i][1]-k;
            x12 = line[i][0]+k;
            y12 = line[i][1]+k;

            int x21, y21, x22, y22, l2, r2, t2, d2;
            x21 = line[i][2]-k;
            y21 = line[i][3]-k;
            x22 = line[i][2]+k;
            y22 = line[i][3]+k;

            for (int j=0; j<num; j++) {
                l1 = x11 > rect[j][0] ? x11 : rect[j][0];
                t1 = y11 > rect[j][1] ? y11 : rect[j][1];
                r1 = x12 < rect[j][2] ? x12 : rect[j][2];
                d1 = y12 < rect[j][3] ? y12 : rect[j][3];
                l2 = x21 > rect[j][0] ? x21 : rect[j][0];
                t2 = y21 > rect[j][1] ? y21 : rect[j][1];
                r2 = x22 < rect[j][2] ? x22 : rect[j][2];
                d2 = y22 < rect[j][3] ? y22 : rect[j][3];
                if ((l1 > r1 || t1 > d1) && (l2 > r2 || t2 > d2))
                    continue;
                if (l1 <= r1 && t1 <= d1)
                    setTemp(next_num++, l1, t1, r1, d1);

                if (l2 <= r2 && t2 <= d2)
                    setTemp(next_num++, l2, t2, r2, d2);
            }
            if (next_num == 0) {
                return false;
            }
            num = next_num;
            moveTempToRect(num);
        }
    }
    return true;
}

void swap (int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(int argc, char** argv) {
    /* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
       앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
       만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
       그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
       또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
       단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
    //freopen("input.txt", "r", stdin);

    setbuf(stdout, NULL);
    int TC;
    int test_case;
    scanf("%d", &TC);	// cin 사용 가능
    for(test_case = 1; test_case <= TC; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오.
        int n, x1, x2, y1, y2;
        scanf("%d",&n);
        for (int i=0; i<n; i++) {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if (x1 == x2) {
                vert[i] = true;
                if (y1 > y2)
                    swap(&y1, &y2);
            } else {
                vert[i] = false;
                if (x1 > x2)
                    swap(&x1, &x2);
            }
            line[i][0] = 2*x1;
            line[i][1] = 2*y1;
            line[i][2] = 2*x2;
            line[i][3] = 2*y2;
        }
        int left = -1, right = 1024*1024*128, mid = (left + right)/2;
        while(left+1 != right){
            if (check(n, mid))
                right = mid;
            else
                left = mid;
            mid = (left + right)/2;
        }

        // 이 부분에서 정답을 출력하십시오.
        printf("Case #%d\n", test_case);	// cout 사용 가능
        printf("%d", right/2);
        if (right%2==1)
            printf(".5");
        printf("\n");
    }

    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}

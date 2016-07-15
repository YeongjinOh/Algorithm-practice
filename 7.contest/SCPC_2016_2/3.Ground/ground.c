#include <stdio.h>
int x_mine[100000][2]; // sorted by x
int y_mine[100000][2]; // sorted by y
int max[100001];

int main(void) {
    /* 아래 freopen 함수는 sample_input.txt를 read only 형식으로 열고, 표준입력(키보드) 대신 sample_input.txt 로 부터 읽어오겠다는 의미의 코드입니다.
       만약 본인 PC 에서 테스트 할 때는, 입력값을 sample_input.txt에 저장한 후 freopen 함수를 사용하면
       그 아래에서 scanf 함수를 사용하여 표준입력 대신 sample_input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
       또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
       단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야만 합니다. */
    // freopen("sample_input.txt", "r", stdin);

    /* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 '시간 초과'로 강제 종료 되었을 때,
       printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
       시간 초과 전까지 실행된 결과 점수를 받고자 하신다면 "setbuf(stdout, NULL);" 를 사용하시기 바랍니다. */
    setbuf(stdout, NULL);

    int T;
    int test_case;

    scanf("%d", &T);
    for(test_case = 1; test_case <= T; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.

        int n, i, j, x, y, flag;
        int total[2] = {0,0};
        scanf("%d",&n);
        for(i=0; i<n; i++) {
            scanf("%d",&x);
            scanf("%d%d",&y,&flag);
            x_mine[x-1][0] = y;
            y_mine[y-1][0] = x;
            y_mine[y-1][1] = flag;
            x_mine[x-1][1] = flag;
            total[flag]++;
            max[i] = 0;
        }
        max[n] = 0;
        max[0] = total[0];
        int res = max[0];
        int max_idx = 0;
        // from the left to the right
        for (i=0; i<n; i++) {
            if (x_mine[i][1] == 0)
                max[i+1] = max[i]-1;
            else
                max[i+1] = max[i]+1;
            if (res < max[i+1]) {
                res = max[i+1];
                max_idx = i+1;;
            }
        }
        int start = 0;
        int last = n-1;

        // from the bottom to the top
        for (i=0; i<n; i++) {
            x = y_mine[i][0];
            flag = y_mine[i][1];
            if (flag == 0) {
                for (j=start; j<x; j++)
                        max[j]--;
                for (j=x; j<=last; j++) {
                        max[j]++;
                }
            } else {
                 for (j=start; j<x; j++)
                        max[j]++;
                for (j=x; j<=last; j++) {
                        max[j]--;
               }
            }
            for (j=start; j<=last; j++)
                if (res < max[j]) {
                    res = max[j];
                }
        }

        // 이 부분에서 정답을 출력하십시오.
        printf("Case #%d\n", test_case);
        printf("%d\n", res);
//        for (i=0; i<=n; i++)
//            printf("max:%d\n",max[i]);

    }

    return 0;   // 정상종료 시 반드시 0을 리턴해야 합니다.
}


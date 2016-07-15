#include <stdio.h>

int P[10000];
int Q[10000];
int pay[10000];

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

        // the number of weeks
        int n, i, j;
        scanf("%d", &n);
        for (i=0; i<n; i++)
            scanf("%d", &P[i]);
        for (i=0; i<n; i++)
            scanf("%d", &Q[i]);

        // initailize payment
        for (i=0; i<n; i++)
            pay[i] = 0;
        pay[0] = P[0]>Q[0]?P[0]:Q[0];
        if (n>1) {
            pay[1] = pay[0]+P[1]>Q[1]?pay[0]+P[1]:Q[1];
        }
        for (i=2; i<n; i++) {
            pay[i] = pay[i-1]+P[i]>pay[i-2]+Q[i]?pay[i-1]+P[i]:pay[i-2]+Q[i];
        }

        // 이 부분에서 정답을 출력하십시오.
        printf("Case #%d\n", test_case);
        printf("%d\n",pay[n-1]);
    }

    return 0;   // 정상종료 시 반드시 0을 리턴해야 합니다.
}


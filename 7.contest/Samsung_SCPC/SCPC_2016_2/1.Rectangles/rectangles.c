#include <stdio.h>
#include <stdbool.h>

int rect[5000][6];
int children[5000]; // number of children

void swap(int i, int j) {
    int temp[6];
    int k;
    for (k=0; k<6; k++) {
        temp[k] = rect[i][k];
        rect[i][k] = rect[j][k];
        rect[j][k] = temp[k];
    }
}


int partition (int idx, int p, int r)
{
	int pivot = rect[r][idx];
	int j, i=p-1;

	for (j=p; j<r; j++) {
		if (rect[j][idx] < pivot) {
			i++;
			swap(i, j);
		}
	}
	swap(i+1, r);

	return i+1;
}

void quick_sort_helper(int idx, int p, int r)
{
	if (p<r)
	{
		int q = partition (idx, p, r);
		quick_sort_helper(idx, p, q-1);
		quick_sort_helper(idx, q+1, r);
	}
}

// quick sort
void sort(int LENGTH, int idx)
{
	quick_sort_helper(idx, 0, LENGTH-1);
}

bool isIncluded (int parent, int child) {
    return (rect[parent][0] <= rect[child][0] && rect[parent][1] <= rect[child][1] &&
            rect[parent][2] >= rect[child][2] && rect[parent][3] >= rect[child][3]);
}

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

        int m,n,k,i,j;
        scanf("%d%d%d",&m,&n,&k);

        // get rectangle informations : x1, y1, x2, y2, width, height
        for (i=0; i<k; i++) {
            scanf("%d%d%d%d",&rect[i][0],&rect[i][1],&rect[i][2],&rect[i][3]);
            rect[i][4] = rect[i][2] - rect[i][0];
            rect[i][5] = rect[i][3] - rect[i][1];
        }

        // sort
        sort(k, 4);
        int cur, prev;
        i=0;
        while(i<k) {
            prev = i;
            cur = rect[i][4];
            while(cur == rect[i+1][4] && i+1<k) {i++;}
            if (prev != i) {
                quick_sort_helper(5,prev,i);
            }
            i++;
        }

        // initialize the number of children
        for (i=0; i<k; i++) {
            children[i] = 0;
        }

        int max = 0;
        for (i=1; i<k; i++) {
            for (j=0; j<i; j++) {
                if (isIncluded(i,j) && children[i] < children[j] + 1) {
                    children[i] = children[j]+1;
                    if (max < children[i])
                        max = children[i];
                }
            }
        }

        // 이 부분에서 정답을 출력하십시오.
        printf("Case #%d\n", test_case);
        printf("%d\n",max+1);
    }

    return 0;   // 정상종료 시 반드시 0을 리턴해야 합니다.
}


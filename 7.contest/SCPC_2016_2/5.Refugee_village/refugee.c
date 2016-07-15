#include <stdio.h>
double refugee[20][2];
double supply[20];
double absolute(double a) { return a>0?a:-a;}
double max (double a, double b) { return a>b?a:b;}
double d(int idx, double x, double y) { return absolute(refugee[idx][0]-x) + absolute(refugee[idx][1]-y);
}

void swap (double val[], int i, int j){ double tmp = val[i];    val[i] = val[j];    val[j] = tmp; }
int partition (double val[], int p, int r)
{
    double pivot = val[r];
    int j, i=p-1;

    for (j=p; j<r; j++) {
        if (val[j] > pivot) {
            i++;
            swap(val, i, j);
        }
    }
    swap(val, i+1, r);

    return i+1;
}

void quick_sort_helper(double val[], int p, int r)
{
    if (p<r)
    {
        int q = partition (val, p, r);
        quick_sort_helper(val, p, q-1);
        quick_sort_helper(val, q+1, r);
    }
}

void quick_sort(double val[], int LENGTH)
{
    quick_sort_helper(val, 0, LENGTH-1);
}

double get_max (int n, double x, double y) {
    int i;
    double m=0;
    for (i=0; i<n; i++) {
        m = max(m, d(i,x,y));
    }
    return m;
}

// get x with optimal d
double get_x (int n, double x, double y, double step) {
    double cur = get_max(n,x,y);
    while(cur > get_max(n,x+step,y)) {
        cur = get_max(n,x+step,y);
        x = x + step;
    }
    return x;
}

double get_y (int n, double x, double y, double step) {
    double cur = get_max(n,x,y);
    while(cur > get_max(n,x,y+step)) {
        cur = get_max(n,x,y+step);
        y = y + step;
    }
    return y;
}

double get_u (int n, int k, double x, double y) {
    double d_val[n]; // array of d values
    int i;
    for (i=0; i<n; i++) {
        d_val[i] = d(i,x,y);
    }
    // sort the array of d values in decreasing order
    quick_sort(d_val, n);

    // get u by adding supplies
    for (i=0; i<k; i++)
        d_val[n-1-i] += supply[i];

    // return value which is maximal of u
    double res = 0;
    for (i=0; i<n; i++)
        if(res < d_val[i])
            res = d_val[i];
    return res;
}

// get x with optimal u
double get_xu (int n, int k, double x, double y, double step) {
    double cur = get_u(n,k,x,y);
    double next = get_u(n,k,x+step,y);
    while(cur > next) {
        cur = next;
        x = x + step;
        next = get_u(n,k,x+step,y);
    }
    return x;
}
double get_yu (int n, int k, double x, double y, double step) {
    double cur = get_u(n,k,x,y);
    double next = get_u(n,k,x,y+step);
    while(cur > next) {
        cur = next;
        y = y + step;
        next = get_u(n,k,x,y+step);
    }
    return y;
}


// get minimal (max u) around (x,y)
double get_around_u(int n, int k, double x, double y, int radius) {
    double step = 0.5;
    // start from the bottom-left corner
    double xi = x-step*radius;
    double yi = y-step*radius;
    int i;
    double min=999999999, cur;

    // to the right
    for (i=0; i<radius*2; i++) {
        cur = get_u(n, k, xi, yi);
        if (min > cur)  min = cur;
        xi++;
    }
    // to the top
    for (i=0; i<radius*2; i++) {
        cur = get_u(n, k, xi, yi);
        if (min > cur)  min = cur;
        yi++;
    }
    // to the left
    for (i=0; i<radius*2; i++) {
        cur = get_u(n, k, xi, yi);
        if (min > cur)  min = cur;
        xi--;
    }
    // to the bottom
    for (i=0; i<radius*2; i++) {
        cur = get_u(n, k, xi, yi);
        if (min > cur)  min = cur;
        xi--;
    }
    return min;
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
    double min_step = 0.5;
    scanf("%d", &T);
    for(test_case = 1; test_case <= T; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.

        /// n is the number of refugees, and k is the number of supplies
        int n,k,i,j;
        scanf("%d%d", &n, &k);
        for (i=0; i<n; i++)
            scanf("%lf%lf", &refugee[i][0], &refugee[i][1]);
        for (i=0; i<k; i++)
            scanf("%lf",&supply[i]);

        // sort supply
        quick_sort(supply, k);

        // guess the best position of avg
        double step = 50000;
        double x=0, y=0;
        /*
           while(step>=min_step) {
           x = get_x(n,x,y,step);
           x = get_x(n,x,y,-step);
           y = get_y(n,x,y,step);
           y = get_y(n,x,y,-step);
           step/=10;
           }
           */

        // find the best position of avg
        step = 50000;
        while(step>=min_step) {
            x = get_xu(n,k,x,y,step);
            x = get_xu(n,k,x,y,-step);
            y = get_yu(n,k,x,y,step);
            y = get_yu(n,k,x,y,-step);
            step/=10;
        }

        // find the minimal around the best position
        double min = get_u(n,k,x,y);
        double cur;
        step = min_step;
        int max_iteration=10000;
        for (i=1; i<max_iteration; i++) {
            step = 0.5 * i;
            x = get_xu(n,k,x,y,step);
            x = get_xu(n,k,x,y,-step);
            y = get_yu(n,k,x,y,step);
            y = get_yu(n,k,x,y,-step);
            cur = get_u(n,k,x,y);
            if (min > cur)
                min = cur;
            else
                break;
        }
        double prev_min = min;
        int radius = 1;
        do {
            prev_min = min;
            for (i=1; i<300; i++) {
                cur = get_around_u(n,k,x,y,radius++);
                if (min > cur)
                    min = cur;
            }
        } while(prev_min > min && radius < 3000);
        // 이 부분에서 정답을 출력하십시오.
        printf("Case #%d\n", test_case);
        printf("%.1f\n",min);

    }

    return 0;   // 정상종료 시 반드시 0을 리턴해야 합니다.
}


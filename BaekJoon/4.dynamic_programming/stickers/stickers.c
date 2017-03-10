#include <stdio.h>
int max(int a, int b){ return a>b?a:b; }
int main() {
    // number of test cases
    int T;
    scanf("%d", &T);
    while(T--) {
         
        // number of columns
        int col, i;
        scanf("%d",&col);
        int top_score[col];
 
        // get scores
        for (i=0; i<col; i++) 
            scanf("%d",&top_score[i]);
     
        // top, down, none means the position of sticker taken at current state.
        int top=0, down=0, none=0, prev_top, prev_down, down_score;
 
        for (i=0; i<col; i++) {
            scanf("%d", &down_score);
 
            prev_top = top;
            prev_down = down;
             
            top = max(prev_down, none) + top_score[i];
            down = max(prev_top, none) + down_score;
            none = max(prev_down, prev_top);        
        }
        printf("%d\n", max(top,down));
    }
}

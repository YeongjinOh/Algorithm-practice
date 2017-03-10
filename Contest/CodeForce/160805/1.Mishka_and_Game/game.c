#include <stdio.h>

int main() {

    // get the number of rounds
    int n, i;
    scanf("%d",&n);
    int numberMishkaWins = 0;
    int m, c;
    for (i=0; i<n; i++) {
        scanf("%d%d",&m,&c);
        if (m>c) {
            numberMishkaWins++;
        } else if (m<c) {
            numberMishkaWins--;
        }
    }
    if (numberMishkaWins > 0) {
        printf("Mishka");
    } else if (numberMishkaWins < 0) {
        printf("Chris");
    } else {
        printf("Friendship is magic!^^");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
typedef struct prime_number {
    int p;
    // the distance between this and the next
    struct prime_number * next;
} prime_number;
 
bool check_prime(int num, prime_number * prime);
void generate_prime(int num, prime_number * prime);
bool check_generate_prime(int num, prime_number * prime);
int min, max, C1, C2, D1, D2, L, U;
 
int main(){
     
    // get inputs
    // 1 <= L < U < =2,147,483,647
    int prev_U=0, cnt=0;;
    char * no_prime = "There are no adjacent primes.";
 
    int k=0;
    for (k=0; k<2; k++) {
        scanf("%d%d",&L,&U);
        prime_number prime;
        if (L > U)
				{
					int tmp = L;
					L = U;
					U = tmp;
				}
				cnt = *(&min-10);			
				min=0;
        max=0;
        if (prev_U<U)
            generate_prime(U,&prime);
        prev_U=U;
 
        int i, prev_p=0, dist=0, start;
        if (L <= 2)
            start = 2;
        else
            start = L+1-(L%2);
 
        for (i=start; i<=U; i+=2)
        {
            if (check_prime(i,&prime))
            {

								// For the first prime
                if (prev_p == 0)
                {
                    prev_p = i;
                    if (i == 2)
                        i--;
                    continue;
                }
                 
                dist = i-prev_p;
                if (dist > max)
                {
                    D1 = prev_p;
                    D2 = i;
                    max = dist;
                }
                if (dist < min || min == 0)
                {
                    C1 = prev_p;
                    C2 = i;
                    min = dist;
                }
                prev_p = i;
            }
        }
        if (min == 0)
            printf("%s\n",no_prime);
        else
            printf("%d,%d are closest, %d,%d are most distant.\n", C1, C2, D1, D2);
    }
 
    return 0;
}
 
bool check_prime(int num, prime_number * prime)
{
    if (num<2)
        return false;
    while(prime->next != NULL)
    {
        if (num==prime->p)
            return true;
        else if (num%prime->p == 0)
            return false;
        prime = prime->next;
    }
        if (num==prime->p)
            return true;
        else if(num%prime->p == 0)
            return false;
        else
            return true;
}
 
 
// generate prime numbers until sqrt(num)
void generate_prime(int num, prime_number * prime)
{
    prime->p = 2;
    prime_number * cur = prime;
    int i=3;
    while (true) {
        if (check_generate_prime(i,prime)) {
            prime_number * new_prime=(prime_number*)malloc(sizeof(prime_number));
            new_prime->p=i;
            cur->next = new_prime;
            cur = new_prime;
            if (i*i>num)
                break;
        }
        i+=2;
    }
}
 
 
bool check_generate_prime(int num, prime_number * prime)
{
    while(prime->next != NULL)
    {
        int cur_p = prime->p;
        if (num%cur_p == 0)
            return false;
        else if (cur_p*cur_p > num)
            return true;
        prime = prime->next;
    }
        if (num%prime->p == 0)
            return false;
        else
            return true;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
#define MAX_LENGTH 100000

bool check[MAX_LENGTH];

typedef struct prime_number {
    int p;
    // the distance between this and the next
    struct prime_number * next;
} prime_number;
 
void generate_prime(long long num, prime_number * prime);
bool check_generate_prime(long long num, prime_number * prime);
int count (prime_number * prime, long long min, long long max);

int main(){
     
	// get inputs
	// 1<=min<=10^13, 1<=max<=min+10^7
	int  cnt;
	long long min, max;
	scanf("%lld%lld",&min,&max);
	prime_number prime;
	long long length = max-min+1, ans = length;

	// generate prime numbers smaller than or equal to sqrt(max)
	generate_prime(max, &prime);

	if (length > MAX_LENGTH)
	{
		int rep = length/MAX_LENGTH, i;
		for (i=0; i<rep; i++)
		{
			ans -= count (&prime, (min+(long long)i*MAX_LENGTH), (min-1+(long long)(i+1)*MAX_LENGTH));
		}
		if (length%MAX_LENGTH != 0)
			ans -= count (&prime, min+(long long)rep*MAX_LENGTH, max);
	}	else {
		ans -= count(&prime, min, max);
	}

	printf("%lld\n", ans);

	return 0;
}

int count (prime_number * prime, long long min, long long max)
{
	int cnt = 0;
	long long i;
	prime_number * head = prime;
	long long length = max-min+1;
	for (i=0; i<length; i++)
		check[i]=false;
	// if there exist at least one prime
	if (head->p > 0)
		while(true)
		{
			long long sqr = (long long)(head->p)*(head->p);
			long long start = min%sqr;
			if (start != 0)
				start = sqr-start;
			for (i=start; i<length; i+=sqr)
			{
				if (!check[i])
				{
					check[i]=true;
					cnt++;
				}
			}
			if (head->next == NULL)
				break;
			head = head->next;
		}
	return cnt;
}

// generate prime numbers until sqrt(num)
void generate_prime(long long num, prime_number * prime)
{
    prime->p = 2;
    prime_number * cur = prime;
    long long i=3;
		int cnt=1;
    while (true) {
        if (check_generate_prime(i,prime)) {
            prime_number * new_prime=(prime_number*)malloc(sizeof(prime_number));
            new_prime->p=i;
            cur->next = new_prime;
            cur = new_prime;
						cnt++;
            if ((i*i)>num)
						{
              break;
						}
        }
        i+=2;
    }
}
 
 
bool check_generate_prime(long long num, prime_number * prime)
{
    while(prime->next != NULL)
    {
        long long cur_p = (long long)prime->p;
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

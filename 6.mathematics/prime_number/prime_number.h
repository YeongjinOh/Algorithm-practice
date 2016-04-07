#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// the structure of prime_number
// each structure has it's integer value and the pointer of the next prime_number
typedef struct prime_number {
	int p;
	struct prime_number * next;
} prime_number;

void generate_prime(int num, prime_number * prime);
void print_prime(prime_number * prime);
bool check_generate_prime(int num, prime_number * prime);
bool check_prime(int num, prime_number * prime);
int count_prime(prime_number * head);

void generate_prime(int num, prime_number * prime)
{
	prime->p = 2;
	prime_number * tail = prime;
	int i=3;
	while (i<=num) {
		if (check_generate_prime(i,prime)) {
			prime_number * new_prime=(prime_number*)malloc(sizeof(prime_number));
			new_prime->p=i;
			tail->next = new_prime;
			tail = new_prime;
		}
		i++;
	}
}

void print_prime(prime_number * prime)
{
	while(prime->next != NULL)
	{
		printf("%d ",prime->p);
		prime = prime->next;
	}
		printf("%d\n",prime->p);
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

bool check_prime(int num, prime_number * prime)
{
	while(prime->next != NULL)
	{
		int cur_p = prime->p;
		if (num == cur_p)
			return true;
		prime = prime->next;
	}
			return false;
}


int count_prime(prime_number * head)
{
	int i=1;
	prime_number * curr = head;
	while (curr->next != NULL)
	{
		curr = curr->next;
		i++;
	}
	return i;
}

#include <stdio.h>
#include <stdbool.h>

void longlong_to_boolean (long long num, bool boolean[], int * length)
{
	int i=0;
	for (i=0; i<60 && num>0; i++) {
		boolean[i]=num%2;
		num/=2;
	}
	(*length) = i;
}

long long boolean_to_longlong (bool boolean[], int length)
{
	long long num = 0;
	int i;
	for(i=length-1; i>=0; i--)
		num = num*2 + boolean[i];
	return num;
}

void print_boolean (bool boolean[])
{
	int i;
	for (i=59; i>=0; i--)
		printf("%d", boolean[i]);
	printf("\n");
}

// left ^= right;
void xor (bool left[], bool right[], int * left_length, int right_length)
{
	int i;
	if (*left_length < right_length) {
			for (i=0; i<*left_length; i++)
				left[i]^=right[i];
			for (i=*left_length; i<right_length; i++)
				left[i] = right[i];
			*left_length = right_length;
	} else {
		for (i=0; i<right_length; i++)
			left[i]^=right[i];
	}
}

int main(void)
{

	// get the input sequence of integers
	int K, i, j;
	scanf("%d",&K);
	long long read;
	bool query[K+1][60];
	int length[K+1];

	// for the (k+1)-th element Q(k+1) = Q1 xor Q2 xor ... xor Qk
	longlong_to_boolean(0, query[K], &length[K]);

	for (i=0; i<K; i++)	{
		scanf("%lld",&read);
		longlong_to_boolean(read, query[i], &length[i]);
		if (i > 0)
			xor (query[i], query[i-1], &length[i], length[i-1]);		
	}

	// get the query information
	int Q, result_length, l, r;
	long long left, right;
	bool result[60];
	scanf("%d",&Q);
	while(Q--) {
		longlong_to_boolean(0, result, &result_length);

		scanf("%lld%lld",&left,&right);
		// process l and r
		l = (left-1)%(K+1);
		r = (right-1)%(K+1);
		if (l > r) {
			int tmp;
			tmp = l;
			l = r+1;
			r = tmp-1;
		}

		// calculate the xor result
		if (l==0)
			printf("%lld\n",boolean_to_longlong(query[r], length[r]));
		else {
			xor (result, query[l-1], &result_length, length[l-1]);
			xor (result, query[r], &result_length, length[r]);
			printf("%lld\n",boolean_to_longlong(result, result_length));
		}
	}
	
	return 0;
}

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LENGTH 10000
#define MOD 100000

// Default : descending order
int back_up[LENGTH];

void merge_sort_helper(int val[], int i, int j)
{
	int mid = (i+j)/2;
	if (i != mid)
		merge_sort_helper(val, i, mid);
	if (mid+1 != j)
		merge_sort_helper(val, mid+1, j);
	int length=j-i+1, tmp[length], k;
	for (k=0; k<length; k++)
		tmp[k] = val[k+i];

	int l=0, r=(mid+1)-i;
	for (k=0; k<length; k++)
		if (l > mid-i)
			val[k+i]=tmp[r++];
		else if (r > j-i)
			val[k+i]=tmp[l++];
		else if (tmp[l] > tmp[r])
			val[k+i] = tmp[l++];
		else
			val[k+i] = tmp[r++];
}

void merge_sort(int val[])
{
	merge_sort_helper(val,0,LENGTH-1);
}

void bubble_sort(int val[])
{
	int i, j, tmp;
	for (i=LENGTH-1; i>0; i--)
	{
		bool swapped = false;
		for (j=0; j<i; j++)
			if (val[j] < val[j+1])
			{
				tmp = val[j];
				val[j] = val[j+1];
				val[j+1] = tmp;
				swapped = true;
			}
		if (!swapped)
			break;
	}
}

void insertion_sort(int val[])
{
	int i, j, tmp;
	for (i=1; i<LENGTH; i++)
		for (j=i; j>0 && val[j-1]<val[j]; j--)
		{
			tmp = val[j];
			val[j] = val[j-1];
			val[j-1] = tmp;
		}
}

void set_array(int rand_num[])
{
	int i;
	for (i=0; i<LENGTH; i++)
		rand_num[i] = back_up[i];
}

bool check(int val[])
{
	int i;
	for (i=0; i<LENGTH-1; i++)
		if (val[i] < val[i+1])
			return false;
	return true;
}


void sort(void (*sort_func)(int *), char * sort_name) 
{
	// initialization
	clock_t begin, end;
	double time_spent;
	int rand_num[LENGTH];
	set_array(rand_num);
	
	// sort the random number array
	begin = clock();
	(*sort_func)(rand_num);
	end = clock();
	time_spent = (double)(end - begin)/CLOCKS_PER_SEC*1000;
	if (check(rand_num))
		printf("%s sort takes %.1f(ms)\n",sort_name, time_spent);
	else
	{
		int i;
		printf("%s sort fails\n",sort_name);
		for (i=0; i<LENGTH; i++)
			printf("%d ",rand_num[i]);
		printf("\n");
	}
}

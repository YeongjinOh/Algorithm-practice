#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LENGTH 10000
#define MOD LENGTH*100

// Default : descending order
int back_up[LENGTH];

/* Utils */

void swap (int val[], int i, int j){	int tmp = val[i];	val[i] = val[j];	val[j] = tmp; }

void print(int val[], int cnt)
{
	int i;
	for (i=0; i<cnt && i<LENGTH; i++)
		printf("%d ",val[i]);
}

void reverse(int val[]) {
	int i;
	for (i=0; i<LENGTH/2; i++)
		swap(val, i, LENGTH-i-1);
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
		{
			printf("At %d-th : %d <  %d\n", i, val[i], val[i+1]);
			return false;
		}
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
/* Counting sort */
void counting_sort (int val[])
{
	int i, C[MOD];
	for (i=0; i<MOD; i++)
		C[i] = 0;
	for (i=0; i<LENGTH; i++)
		C[val[i]]++;
	for (i=1; i<MOD; i++)
		C[i] += C[i-1];
	
	int B[LENGTH];
	for (i=LENGTH-1; i>=0; i--)
		B[--C[val[i]]]=val[i];

	for (i=0; i<LENGTH; i++)
		val[i] = B[LENGTH-i-1];
}



/* Heap sort*/

int left_child(int idx) { return 2*idx+1; }
int right_child(int idx){ return 2*idx+2; }
int parent(int idx)			{ return (idx-1)/2; }

void min_heapify (int val[], int idx, int length)
{
	int left, right, tmp, next, cur = idx;
	while (cur < length) {
		left = left_child(cur);
		right = right_child(cur);
		
		next = cur;
		if (left < length && val[left] < val[next])
			next = left;

		if (right < length && val[right] < val[next])
			next = right;

		if (cur == next)
			break;
		
		swap (val, cur, next);
		cur = next;
	}
}

void build_min_heap(int val[])
{
	int i;
	for (i=parent(LENGTH-1); i>=0; i--)
		min_heapify (val, i, LENGTH);
}

void heap_sort(int val[])
{
	int i;

	build_min_heap(val);
	for (i=LENGTH-1; i>0; i--)	{
		swap(val, 0, i);
		min_heapify (val, 0, i);
	}
}

/* Quick sort */

int partition (int val[], int p, int r)
{
	int pivot = val[r];
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

// find the i-th largest element in the subarray val[p..r]
int selection (int val[], int p, int r, int i) 
{
	// base case
	if (p==r)
		return val[p];

	int q = partition (val, p, r);
	int k = q-p+1;
	if (k == i)
		return val[k];
	else if (k > i)
		return selection (val, p, q-1, i);
	else
		return selection (val, q+1, r, i-k);


}

void quick_sort_helper(int val[], int p, int r)
{
	if (p<r)
	{
		int q = partition (val, p, r);
		quick_sort_helper(val, p, q-1);
		quick_sort_helper(val, q+1, r);
	}
}

void quick_sort(int val[])
{
	quick_sort_helper(val, 0, LENGTH-1);
}



/* Merge sort */

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


/* Bubble sort */

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


/* Insertion sort */

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



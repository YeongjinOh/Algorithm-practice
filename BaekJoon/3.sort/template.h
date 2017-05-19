#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LENGTH 10000
#define MOD (LENGTH*100)

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

/* Radix sort */
void radix_sort (int val[]) {
}

/* Counting sort */
void counting_sort (int val[]) {
}



/* Heap sort*/
void heap_sort(int val[]) {
}



/* Quick sort */
void quick_sort(int val[]) {
}

/* Merge sort */
void merge_sort(int val[]){
}


/* Bubble sort */

void bubble_sort(int val[]){
}


/* Insertion sort */

void insertion_sort(int val[]) {
}



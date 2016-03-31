#include <stdio.h>
 
#define DEFAULT_VALUE  -1
 
 
void bubble_sort(int val[], int length)
{
    int i, j, tmp;
    for (i=length-1; i>0; i--)
    {
        for (j=0; j<i; j++)
            if (val[j] < val[i])
            {
                tmp = val[j];
                val[j] = val[i];
                val[i] = tmp;
            }
    }
}
 
 
int main(void)
{
    // Get the input n, k
    int n,k;
    scanf("%d %d",&n,&k);
 
    // Get the values of coin
    int value[n];
    int i;
    for (i=0; i<n; i++)
        scanf("%d",&value[i]);

    // Define minimum array
    int size = 10001;
    int  min[size];
    int j;
     
    // make value array in descending order
    bubble_sort(value,n);
     
    // erase overlapping value
    for (i=0; i<n-1; i++)
        if(value[i] == value[i+1])  {
            for (j=i+1; j<n-1; j++)
            {
                value[j] = value[j+1];
            }
            n--;
            i--;
        }
     
   

    // to use this inequation, (M-(v1v2+...+vn-1vn))/v1 < a1
    int new_k = k;
    for (i=0; i<n-1; i++)
       new_k -= value[i]*value[i+1];

		if (new_k < 0)
			new_k = 0;

    int max = value[0];
    int minCoeff = (int)(new_k/max);
    
		// reduce k
		new_k = k-minCoeff*max;
		if (new_k > 0)
			k = new_k;
		else
			minCoeff = 0;
 
    // Initialize min array with DEFAULT_VALUE
    for (i=0; i<size; i++)
            min[i]=DEFAULT_VALUE;
    for (i=0; i<n; i++)
    {
        if(value[i]>=size)
            continue;
        min[value[i]]=1;
    }
 
    // Calculate minimum times when k=sum
    int sum;
    for (i=0; i<n; i++)
    {
        for (sum=value[i]; sum<=k; sum++)
        {
            if (min[sum-value[i]] == DEFAULT_VALUE)
                continue;
            else if (min[sum] == DEFAULT_VALUE || min[sum-value[i]]+1 < min[sum])
                min[sum] = min[sum-value[i]]+1;
 
        }
    }
 
    // Print minimum value
    if (min[k] <= 0)
        printf("-1\n");
    else
			printf("%d\n",min[k]+minCoeff);
 
    return 0; 
}

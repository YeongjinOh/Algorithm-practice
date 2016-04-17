#include <stdio.h>

double R[10];

double equivalent_ohms ()
{
	double ohms;
	char read='(';
	// 1 if series, 2 if parallel
	int flag = 0;
	while (read != ')')
	{
		scanf("%c",&read);
		// seires
		if (flag == 1) {
			if (read == '(')
				ohms += equivalent_ohms();
			else if (read >= '1' && read <= '9')
				ohms += R[read-'1'];

		// parallel
		} else if (flag == 2) {
			if (read == '(')
				ohms += 1/equivalent_ohms();
			else if (read >= '1' && read <= '9')
				ohms += 1/R[read-'1'];

		// base case
		} else {
			if (read == '(')
				ohms = equivalent_ohms();
			else if (read >= '1' && read <= '9')
				ohms = R[read-'1'];
			else if (read == '-')
				flag = 1;
			else if (read == '|')
			{
				ohms = 1/ohms;
				flag = 2;
			}
		}
	}
	if (flag == 2)
		return 1/ohms;
	else
		return ohms;
}

int main(void)
{
	// the number of types of resister and the value array of resister
	int N, i;
	scanf("%d",&N);
	for (i=0; i<N; i++)
		scanf("%lf",&R[i]);
	char read=' ';
	double ohms;
	
	while (read == ' ' || read == '\n')
		scanf("%c",&read);
	// calculate the equivalent ohms
	if (read == '(')
		ohms = equivalent_ohms();
	else {
		scanf("%c",&read);
		ohms = R[read-'1'];
	}
	
	// prine result
	printf("%.5f\n", ohms);

	return 0;
}



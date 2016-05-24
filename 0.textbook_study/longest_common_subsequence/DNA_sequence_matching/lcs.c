#include <stdio.h>
#include <string.h>

#define MAX_GENE_LEN 5000	// maximum length of gene
#define MAX_LINE_LEN 200	// maximum length of each line when reading file
#define BIN_LEN 100				// (maximum) length of bin
#define BIN_UNIT 50				// difference of every two starting points of bin
#define BLANK '_' 				// default character for not common element

char A[MAX_GENE_LEN], B[MAX_GENE_LEN];

int min (int a, int b) { return a>b?b:a; }

// return the length of LCS
int lcs (char * A_bin, char * B_bin, int A_offset, int B_offset, int A_length, int B_length) {

	int i, j, d[A_length+1][B_length+1];
	char b[A_length][B_length]; // 0 means diagonal, 1 means up, 2 means left direction.

	// initial setting for dynamic array
	for (i=0; i<=A_length; i++) { d[i][0] = 0; } // row-wise
	for (j=1; j<=B_length; j++) { d[0][j] = 0; } // column-wise

	// bottom-up solution building
	for (i=0; i<A_length; i++) {
		for (j=0; j<B_length; j++) {
			if (A[A_offset+i] == B[B_offset+j]) {
				d[i+1][j+1] = d[i][j] + 1;
				b[i][j] = 0;				// go diagonal
			}	else if (d[i][j+1] >= d[i+1][j]) {
				d[i+1][j+1] = d[i][j+1];
				b[i][j] = 1;				// go up
			} else {
				d[i+1][j+1] = d[i+1][j];
				b[i][j] = 2;				// go left
			}
		}
	}

	// construct solution
	i=A_length-1;	j=B_length-1;
	while (i>=0 && j>=0) {
		switch (b[i][j]) {
			case 0: // diagonal
				A_bin[i] = A[A_offset+i];
				B_bin[j] = B[B_offset+j];
				i--; j--;
				break;
			case 1: // up
				A_bin[i] = BLANK;
				i--;
				break;
			case 2: // left
				B_bin[j] = BLANK;
				j--;
				break;
			default : // never reach here
				puts("Array b is constructed wrong.");
				return -1;
		}
	}

	// fill the remaining non-solution elements with BLANK
	if (i<0) {
		for (i=j; i>=0; i--)
			B_bin[i] = BLANK;
	} else {
		for (j=i; j>=0; j--)
			A_bin[j] = BLANK;
	}

	return d[A_length][B_length];
}

int main(int argc, char**argv) {

	// Exception handling
	if (argc != 3) {
		puts("The number of input arguments should be 2");
		return -1;
	}
	if (strcmp(argv[1], "geneA.fasta")!=0 || strcmp(argv[2], "geneB.fasta")!=0) {
		puts("Please type correct input files name: geneA.fasta geneB.fasta");
		return -1;
	}


	/** File reading **/

	// open files
	FILE *geneA, *geneB;
	char buff[MAX_LINE_LEN];
	geneA = fopen(argv[1], "r");
	geneB = fopen(argv[2], "r");
	if (geneA == NULL || geneB == NULL) {
		puts("Can not open file");
		return -1;
	}
	// throw away the first line
	fgets(buff, MAX_LINE_LEN, (FILE*)geneA);
	fgets(buff, MAX_LINE_LEN, (FILE*)geneB);

	// read geneA.fasta
	int i, A_length=0, B_length=0;
	while (fgets(buff, MAX_LINE_LEN, (FILE*)geneA) != NULL) {
		for (i=0; buff[i] != '\n' && i<MAX_LINE_LEN; i++)
			A[A_length++] = buff[i];
	}

	// read geneB.fasta
	while (fgets(buff, MAX_LINE_LEN, (FILE*)geneB) != NULL) {
		for (i=0; buff[i] != '\n' && i<MAX_LINE_LEN; i++)
			B[B_length++] = buff[i];
	}

	// close files
	fclose(geneA);
	fclose(geneB);


	/** Find LCS **/

	char A_bin[BIN_LEN], B_bin[BIN_LEN], A_sol[BIN_LEN], B_sol[BIN_LEN];
	int A_bin_len, B_bin_len, A_idx, B_idx;
	int cur, max=0, max_idx, max_len;

	// Work for each bin of A 
	for (A_idx=0;	A_length-A_idx > BIN_UNIT; A_idx += BIN_UNIT) {
		max = 0;
		A_bin_len = min(BIN_LEN, A_length-A_idx);

		for (B_idx=0;	B_length-B_idx > BIN_UNIT; B_idx += BIN_UNIT) {
			B_bin_len = min(BIN_LEN, B_length-B_idx);

			cur = lcs(A_bin, B_bin, A_idx, B_idx, A_bin_len, B_bin_len);

			// exception handling
			if (cur < 0) {
				puts("The solution of lcs can not be negative");
				return -1;
			}

			if (max < cur) {
				max = cur;
				max_idx = B_idx;
				max_len = B_bin_len;

				// copy solutions
				for (i=0; i<A_bin_len; i++)
					A_sol[i] = A_bin[i];
				for (i=0; i<max_len; i++)
					B_sol[i] = B_bin[i];
			}

		}
		// Print solution for each A
		printf("A%d,B%d\n",A_idx,max_idx);
		for(i=0; i<A_bin_len; i++)
			printf("%c",A_sol[i]);
		puts("");
		for(i=0; i<max_len; i++)
			printf("%c",B_sol[i]);
		puts("");
	}

	// Work for each bin of B
	for (B_idx=0;	B_length-B_idx > BIN_UNIT; B_idx += BIN_UNIT) {
		max = 0;
		B_bin_len = min(BIN_LEN, B_length-B_idx);

		for (A_idx=0;	A_length-A_idx > BIN_UNIT; A_idx += BIN_UNIT) {
			A_bin_len = min(BIN_LEN, A_length-A_idx);

			cur = lcs(A_bin, B_bin, A_idx, B_idx, A_bin_len, B_bin_len);

			// exception handling
			if (cur < 0) {
				puts("The solution of lcs can not be negative");
				return -1;
			}

			if (max < cur) {
				max = cur;
				max_idx = A_idx;
				max_len = A_bin_len;

				// copy solutions
				for (i=0; i<B_bin_len; i++)
					B_sol[i] = B_bin[i];
				for (i=0; i<max_len; i++)
					A_sol[i] = A_bin[i];
			}

		}
		// Print solution for each B
		printf("B%d,A%d\n",B_idx,max_idx);
		for(i=0; i<B_bin_len; i++)
			printf("%c",B_sol[i]);
		puts("");
		for(i=0; i<max_len; i++)
			printf("%c",A_sol[i]);
		puts("");
	}
	
	return 0;
}

#include <stdio.h>

int main(void) {
	char open='{', close='}', comma=',';
	char read;
	int i, newline=0, layer=0;
	do {
		scanf("%c",&read);

		if (read == close) {
			layer--;
			newline = 1;
		}

		// indentation
		if (newline)	{
			printf("\n");
			for (i=0; i<layer; i++)
				printf("  ");
			newline = 0;
		}

		// print
		if (read == open) {
			printf("%c",read);
			layer++;
			newline = 1;
		} else if (read == close) {
			printf("%c",read);
		} else if (read == comma) {
			printf("%c",read);
			newline = 1;
		} else {
			printf("%c",read);
		}
	} while(layer>0);
	
	return 0;
}

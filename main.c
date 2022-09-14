#include<stdio.h>

int array[30000], z;
unsigned int pos;

int main() {
	pos = 0;
	while (getchar() != EOF) {
		switch (getchar()) {
			case '+':
				array[pos]++;
				break;
			case '-':
				array[pos]--;
				break;
			case '<':
				pos--;
				break;
			case '>':
				pos++;
				break;
			case '.':
				printf("%d", array[pos]);
				break;
		}
	}
	return 0;
}

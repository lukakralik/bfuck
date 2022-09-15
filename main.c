#include<stdio.h>

int array[30000], z;
unsigned int pos;

int itoa(int number) {
	return '0' + number;
}
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
				printf("%d", itoa(array[pos]));
				break;
			case '\n': 
				continue;
		}
	}
	return 0;
}

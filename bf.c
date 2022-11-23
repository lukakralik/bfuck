#include <stdbool.h>
#include <stdio.h>

#define LIMIT 255
#define MAX 65535

void inc(int *ptr) { //pointer incrementation
    if (*ptr == MAX) {
        *ptr = 0;
    } else {
        (*ptr)++;
    }
};

void dec(int *ptr) { //pointer decrementation
    if (*ptr == 0) {
        *ptr = LIMIT;
    } else {
        (*ptr)--;
    }
}

int main (int argc, char *argv[]) {
    int dataPtr, data[MAX], instructionPtr, bracketCounter, i;
    char instruction[MAX], c;
    FILE *f;
    f = fopen(argv[1], "r"); //open file from stdin

    for (i = 0; i < MAX; i++) {
        data[i] = 0;
        instruction[i] = '\0';
    }

    instructionPtr = 0;
    while ((c = fgetc(f)) != EOF) {
        instruction[instructionPtr] = c;
        instructionPtr++;
    }

    fclose(f);
    dataPtr = 0;
    instructionPtr = 0;
    bracketCounter = 0;

    while ((c = instruction[instructionPtr]) != '\0') {
        switch (c) {
            case '>':
                inc(&dataPtr);
                break;
            case '<':
                dec(&dataPtr);
                break;
            case '+':
                inc(&data[dataPtr]);
                break;
            case '-':
                dec(&data[dataPtr]);
                break;
            case '.':
                printf("%c", data[dataPtr]);
                break;
            case ',':
                data[dataPtr] = getchar();
                break;
            case '[': //handling loop beggining
                if (data[dataPtr] == 0) {
                    instructionPtr++;

                    while (true) {
                        c = instruction[instructionPtr];
                        if (c == ']' && bracketCounter == 0) {
                            break;
                        } else if (c == ']') {
                            bracketCounter--;
                        } else if (c == '[') {
                            bracketCounter++;
                        }

                        instructionPtr++;
                    }
                }
                break;
            case ']': //handling loop end
                if (data[dataPtr] != 0) {
                    instructionPtr--;
                    while (true) {
                        c = instruction[instructionPtr];

                        if (c == '[' && bracketCounter == 0) {
                            break;
                        } else if (c == '[') {
                            bracketCounter--;
                        } else if (c == ']') {
                            bracketCounter++;
                        }
                        instructionPtr--;
                        continue;
                    }
                }
                break;
        }
        instructionPtr++;
    }
    return 0;
}


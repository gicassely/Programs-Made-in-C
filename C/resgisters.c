#include <stdlib.h>
#include <stdio.h>

#define ELEMENT_COUNT 89478485
#define MAX_AGE 100
#define MAX_SEX 2
#define MAX_STATE 27

int *age;
int *sex;
int *state;
int *result;

int init() {
	int i;

	srand(0);

	age = (int *) malloc(sizeof(int) * ELEMENT_COUNT);
	if (age == NULL) {
		return 1;
	}
	for (i = 0; i < ELEMENT_COUNT; ++i) {
		age[i] = rand() % MAX_AGE;
	}

	sex = (int *) malloc(sizeof(int) * ELEMENT_COUNT);
	if (sex == NULL) {
		return 1;
	}
	for (i = 0; i < ELEMENT_COUNT; ++i) {
		sex[i] = rand() % MAX_SEX;
	}

	state = (int *) malloc(sizeof(int) * ELEMENT_COUNT);
	if (state == NULL) {
		return 1;
	}
	for (i = 0; i < ELEMENT_COUNT; ++i) {
		state[i] = rand() % MAX_STATE;
	}

	return 0;
}

int *search() {
	int i;
	unsigned int count = 0;

	result = (int *) malloc(sizeof(int) * ELEMENT_COUNT);
	if (result == NULL) {
		return NULL;
	}

	for (i = 0; i < ELEMENT_COUNT; ++i)
		result[i] = 0;

	for (i = 0; i < ELEMENT_COUNT; ++i) {
		if (state[i] == 3 || state[i] == 7 || state[i] == 9) {
			if ((age[i] >= 18) && (age[i] <= 45)) {
				if (sex[i] == 0) {
					result[i] = 1;
					count++;
				}
			}
		}
        }

	fprintf(stdout, "%u\n", count);

	return NULL;
}

int main() {
	if (init()) {
		perror("init()");
		return 1;
	}

	(void) search();

	return 0;
}

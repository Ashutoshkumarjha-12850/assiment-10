#include <stdio.h>

int maximum(const int array[], int size) {
	if (size == 1) {
		return array[0];
	}

	int previousMaximum = maximum(array, size - 1);
	return array[size - 1] > previousMaximum
			   ? array[size - 1]
			   : previousMaximum;
}

int countMaximum(const int array[], int size, int maxValue) {
	if (size == 0) {
		return 0;
	}

	return (array[size - 1] == maxValue) +
		   countMaximum(array, size - 1, maxValue);
}

int main(void) {
	int size;
	int array[100];

	printf("Enter the number of elements (1-100): ");
	if (scanf("%d", &size) != 1 || size < 1 || size > 100) {
		printf("Invalid size.\n");
		return 1;
	}

	printf("Enter %d elements: ", size);
	for (int i = 0; i < size; i++) {
		if (scanf("%d", &array[i]) != 1) {
			printf("Invalid input.\n");
			return 1;
		}
	}

	int maxValue = maximum(array, size);
	int occurrences = countMaximum(array, size, maxValue);

	printf("Maximum element: %d\n", maxValue);
	printf("Number of occurrences: %d\n", occurrences);
	return 0;
}

// C program to find the second-largest distinct element in an array using recursion
#include <stdio.h>

// Recursive function to find the largest distinct element
int findLargest(int arr[], int n, int idx, int currMax) {
	if (idx == n) return currMax;
	if (arr[idx] > currMax)
		currMax = arr[idx];
	return findLargest(arr, n, idx + 1, currMax);
}

// Recursive function to find the second-largest distinct element
int findSecondLargest(int arr[], int n, int idx, int largest, int currSecond) {
	if (idx == n) return currSecond;
	if (arr[idx] != largest && arr[idx] > currSecond)
		currSecond = arr[idx];
	return findSecondLargest(arr, n, idx + 1, largest, currSecond);
}

// Helper function to check if there are at least two distinct elements
int hasAtLeastTwoDistinct(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		if (arr[i] != arr[0]) return 1;
	}
	return 0;
}

int main() {
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	if (n <= 0) {
		printf("Array size must be positive.\n");
		return 0;
	}
	int arr[n];
	printf("Enter %d elements:\n", n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	if (!hasAtLeastTwoDistinct(arr, n)) {
		printf("Fewer than two distinct elements exist.\n");
		return 0;
	}

	int largest = findLargest(arr, n, 0, arr[0]);
	// Initialize second largest to a value less than any possible array element
	int secondLargest = findSecondLargest(arr, n, 0, largest, -2147483648);

	if (secondLargest == -2147483648) {
		printf("Fewer than two distinct elements exist.\n");
	} else {
		printf("The second-largest distinct element is: %d\n", secondLargest);
	}
	return 0;
}

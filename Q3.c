#include <stdio.h>

void reverseArray(int arr[], int start, int end) {
	if (start >= end)
		return;
	int temp = arr[start];
	arr[start] = arr[end];
	arr[end] = temp;
	reverseArray(arr, start + 1, end - 1);
}

int main() {
	int n, i;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter %d elements:\n", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	reverseArray(arr, 0, n - 1);

	printf("Reversed array: ");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

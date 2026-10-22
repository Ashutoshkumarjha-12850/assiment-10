#include <stdio.h>

int binarySearch(const int arr[], int low, int high, int key)
{
	if (low > high)
		return -1;

	int mid = low + (high - low) / 2;
	if (arr[mid] == key)
		return mid;
	if (key < arr[mid])
		return binarySearch(arr, low, mid - 1, key);    
	return binarySearch(arr, mid + 1, high, key);
}

int main(void)
{
	int n, key;

	printf("Enter number of elements: ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		printf("Invalid number of elements.\n");
		return 1;
	}

	int arr[n];
	printf("Enter %d elements in sorted order: ", n);
	for (int i = 0; i < n; i++) {
		if (scanf("%d", &arr[i]) != 1) {
			printf("Invalid input.\n");
			return 1;
		}
	}

	printf("Enter element to search: ");
	if (scanf("%d", &key) != 1) {
		printf("Invalid input.\n");
		return 1;
	}

	int index = binarySearch(arr, 0, n - 1, key);
	if (index == -1)
		printf("Element not found.\n");
	else
		printf("Element found at index %d.\n", index);

	return 0;
}

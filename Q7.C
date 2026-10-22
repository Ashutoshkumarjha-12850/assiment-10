#include <stdio.h>

#define MAX 100

int isSymmetric(int matrix[MAX][MAX], int n, int row, int col)
{
	if (row >= n - 1)
		return 1;

	if (col >= n)
		return isSymmetric(matrix, n, row + 1, row + 2);

	if (matrix[row][col] != matrix[col][row])
		return 0;

	return isSymmetric(matrix, n, row, col + 1);
}

int main(void)
{
	int matrix[MAX][MAX];
	int n;

	printf("Enter the order of the square matrix: ");
	if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
		printf("Invalid matrix order.\n");
		return 1;
	}

	printf("Enter the matrix elements:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (scanf("%d", &matrix[i][j]) != 1) {
				printf("Invalid matrix element.\n");
				return 1;
			}
		}
	}

	if (isSymmetric(matrix, n, 0, 1))
		printf("The matrix is symmetric.\n");
	else
		printf("The matrix is not symmetric.\n");

	return 0;
}

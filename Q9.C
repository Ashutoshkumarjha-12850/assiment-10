#include <stdio.h>

#define MAX_SIZE 100

int columnSum(int matrix[MAX_SIZE][MAX_SIZE], int rows, int col, int row)
{
	if (row == rows)
		return 0;

	return matrix[row][col] + columnSum(matrix, rows, col, row + 1);
}

int findMinimumColumn(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols,
					  int col, int minCol, int minSum)
{
	int sum;

	if (col == cols)
		return minCol;

	sum = columnSum(matrix, rows, col, 0);
	if (sum < minSum)
	{
		minSum = sum;
		minCol = col;
	}

	return findMinimumColumn(matrix, rows, cols, col + 1, minCol, minSum);
}

int main(void)
{
	int matrix[MAX_SIZE][MAX_SIZE];
	int rows, cols, i, j;
	int minCol, minSum;

	printf("Enter number of rows and columns: ");
	if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0 ||
		rows > MAX_SIZE || cols > MAX_SIZE)
	{
		printf("Invalid matrix dimensions.\n");
		return 1;
	}

	printf("Enter the matrix elements:\n");
	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			if (scanf("%d", &matrix[i][j]) != 1)
			{
				printf("Invalid matrix element.\n");
				return 1;
			}

	minCol = 0;
	minSum = columnSum(matrix, rows, 0, 0);
	minCol = findMinimumColumn(matrix, rows, cols, 1, minCol, minSum);

	printf("Column with the minimum sum: %d\n", minCol + 1);
	printf("Minimum column sum: %d\n", columnSum(matrix, rows, minCol, 0));

	return 0;
}

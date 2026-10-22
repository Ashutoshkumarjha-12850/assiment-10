#include <stdio.h>

#define MAX 100

void multiplyCell(int first[MAX][MAX], int second[MAX][MAX],
				  int product[MAX][MAX], int row, int column,
				  int index, int common)
{
	if (index == common)
		return;

	product[row][column] += first[row][index] * second[index][column];
	multiplyCell(first, second, product, row, column, index + 1, common);
}

void multiplyMatrices(int first[MAX][MAX], int second[MAX][MAX],
					  int product[MAX][MAX], int rows, int columns,
					  int common, int row, int column)
{
	if (row == rows)
		return;

	multiplyCell(first, second, product, row, column, 0, common);

	if (column + 1 < columns)
		multiplyMatrices(first, second, product, rows, columns, common,
						 row, column + 1);
	else
		multiplyMatrices(first, second, product, rows, columns, common,
						 row + 1, 0);
}

int main(void)
{
	int first[MAX][MAX], second[MAX][MAX], product[MAX][MAX] = {{0}};
	int rows1, columns1, rows2, columns2;

	printf("Enter rows and columns of the first matrix: ");
	if (scanf("%d %d", &rows1, &columns1) != 2 ||
		rows1 < 1 || rows1 > MAX || columns1 < 1 || columns1 > MAX) {
		printf("Invalid matrix dimensions.\n");
		return 1;
	}

	printf("Enter rows and columns of the second matrix: ");
	if (scanf("%d %d", &rows2, &columns2) != 2 ||
		rows2 < 1 || rows2 > MAX || columns2 < 1 || columns2 > MAX) {
		printf("Invalid matrix dimensions.\n");
		return 1;
	}

	if (columns1 != rows2) {
		printf("Matrices are not compatible for multiplication.\n");
		return 1;
	}

	printf("Enter elements of the first matrix:\n");
	for (int i = 0; i < rows1; ++i)
		for (int j = 0; j < columns1; ++j)
			if (scanf("%d", &first[i][j]) != 1)
				return 1;

	printf("Enter elements of the second matrix:\n");
	for (int i = 0; i < rows2; ++i)
		for (int j = 0; j < columns2; ++j)
			if (scanf("%d", &second[i][j]) != 1)
				return 1;

	multiplyMatrices(first, second, product, rows1, columns2, columns1, 0, 0);

	printf("Product matrix (%d x %d):\n", rows1, columns2);
	for (int i = 0; i < rows1; ++i) {
		for (int j = 0; j < columns2; ++j)
			printf("%d\t", product[i][j]);
		printf("\n");
	}

	return 0;
}

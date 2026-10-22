#include <stdio.h>

void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
	if (n <= 0)
	{
		return;
	}

	if (n == 1)
	{
		printf("Move disk 1 from %c to %c\n", source, destination);
		return;
	}

	towerOfHanoi(n - 1, source, destination, auxiliary);
	printf("Move disk %d from %c to %c\n", n, source, destination);
	towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main(void)
{
	int n;

	printf("Enter the number of disks: ");
	if (scanf("%d", &n) != 1 || n <= 0)
	{
		printf("Please enter a positive integer.\n");
		return 1;
	}

	towerOfHanoi(n, 'A', 'B', 'C');
	return 0;
}

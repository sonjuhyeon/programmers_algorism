#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

int	ans_print(int array[], int i, int n)
{
	char	c;

	while (i < n)
	{
		c = array[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return (1);
}

int	queen_ck(int array[], int row, int column)
{
	int	i;

	i = 0;
	while (i < column)
	{
		if (array[i] == row)
			return (0);
		if (array[i] - row == i - column)
			return (0);
		if (array[i] - row == column - i)
			return (0);
		i++;
	}
	return (1);
}

void	recursive(int array[], int *count, int row, int column, int n)
{
	int		i;

	if (column == n)
	{
		ans_print(array, 0, n);
		*count += 1;
		return ;
	}
	i = row;
	while (i < n)
	{
		if (queen_ck(array, i, column))
		{
			array[column] = i;
			recursive(array, count, 0, column + 1, n);
			if (i + 1 < n)
				recursive(array, count, i + 1, column, n);
			return ;
		}
		i++;
	}
	return ;
}


int solution(int n) {
    int answer = 0;
    int array[n];
    
    recursive(array, &answer, 0, 0, n);
    return answer;
}
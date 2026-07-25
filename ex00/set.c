/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiew <ktiew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:00:00 by ktiew             #+#    #+#             */
/*   Updated: 2026/07/25 13:00:06 by ktiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_memory(char **arr, int rows)
{
	int	index;

	if (arr == NULL)
		return ;
	index = 0;
	while (index < rows)
	{
		if (arr[index])
			free(arr[index]);
		index++;
	}
	free(arr);
}

char	**allocate_memory(int rows, int columns)
{
	char	**board;
	int		index;

	index = 0;
	board = (char **)malloc(sizeof(char *) * rows);
	if (board == NULL)
		return (NULL);
	while (index < rows)
	{
		board[index] = (char *)malloc(sizeof(char) * columns);
		if (board[index] == NULL)
			return (NULL);
		index++;
	}
	return (board);
}

char	**create_grid(int size)
{
	char	**grid;
	int		index;
	int		j;

	grid = allocate_memory(size, size);
	index = 0;
	while (index < size)
	{
		j = 0;
		while (j < size)
		{
			grid[index][j] = '0';
			j++;
		}
		index++;
	}
	return (grid);
}

char	**save_clues(char *str, int size)
{
	char	**clues;
	int		index;
	int		j;

	index = 0;
	j = 0;
	clues = allocate_memory(MAX_DIRECTION, size);
	while (j < size)
	{
		clues[0][j] = str[index];
		clues[1][j] = str[index + 2 * size];
		clues[2][j] = str[index + 4 * size];
		clues[3][j] = str[index + 6 * size];
		j++;
		index += 2;
	}
	return (clues);
}

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

void	free_memory(char **str, int rows)
{
	int	index;

	if (str == NULL)
		return ;
	index = 0;
	while (index < rows)
	{
		if (str[index])
			free(str[index]);
		index++;
	}
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

	grid = allocate_memory(size + 2, size + 2);
	index = 0;
	while (index < size + 2)
	{
		j = 0;
		while (j < size + 2)
		{
			grid[index][j] = '0';
			j++;
		}
		index++;
	}
	return (grid);
}

void	put_clues(char **puzzle_grid, char **clues)
{
	int	index;
	int	j;

	index = 1;
	j = 0;
	while (index <= 4)
	{
		puzzle_grid[0][index] = clues[0][j];
		puzzle_grid[5][index] = clues[1][j];
		puzzle_grid[index][0] = clues[2][j];
		puzzle_grid[index][5] = clues[3][j];
		index++;
		j++;
	}
}

char	**save_clues(char *str, int size)
{
	char	**clues;
	int		index;
	int		j;

	index = 0;
	j = 0;
	clues = allocate_memory(size, size);
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

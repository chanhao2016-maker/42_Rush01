/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiew <ktiew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:47:21 by ktiew             #+#    #+#             */
/*   Updated: 2026/07/24 14:47:59 by wchan-ha         ###   ########.fr       */
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

char	**create_grid(void)
{
	char	**grid;
	int		index;
	int		j;

	grid = allocate_memory(6, 6);
	index = 0;
	while (index < 6)
	{
		j = 0;
		while (j < 6)
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

char	**save_clues(char *str)
{
	char	**clues;
	int		index;
	int		j;

	index = 0;
	j = 0;
	clues = allocate_memory(4, 4);
	while (j < 4)
	{
		clues[0][j] = str[index];
		clues[1][j] = str[index + 8];
		clues[2][j] = str[index + 16];
		clues[3][j] = str[index + 24];
		j++;
		index += 2;
	}
	return (clues);
}

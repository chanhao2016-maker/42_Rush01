/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiew <ktiew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:50:17 by ktiew             #+#    #+#             */
/*   Updated: 2025/03/09 15:45:09 by ktiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_right_clue(char **puzzle_grid, int row)
{
	int		index;
	char	visible;
	char	highest;

	index = 4;
	visible = '1';
	highest = puzzle_grid[row][index];
	while (index >= 1)
	{
		if (puzzle_grid[row][index] > highest)
		{
			highest = puzzle_grid[row][index];
			visible++;
		}
		index--;
	}
	return (puzzle_grid[row][5] == visible);
}

int	check_left_clue(char **puzzle_grid, int row)
{
	int		index;
	char	visible;
	char	highest;

	index = 1;
	visible = '1';
	highest = puzzle_grid[row][index];
	while (index <= 4)
	{
		if (puzzle_grid[row][index] > highest)
		{
			highest = puzzle_grid[row][index];
			visible++;
		}
		index++;
	}
	if (puzzle_grid[row][0] == visible)
		return (check_right_clue(puzzle_grid, row));
	return (0);
}

int	check_bottom_clue(char **puzzle_grid, int column)
{
	int		index;
	char	visible;
	char	highest;

	index = 4;
	visible = '1';
	highest = puzzle_grid[index][column];
	while (index >= 1)
	{
		if (puzzle_grid[index][column] > highest)
		{
			highest = puzzle_grid[index][column];
			visible++;
		}
		index--;
	}
	return (puzzle_grid[5][column] == visible);
}

int	check_top_clue(char **puzzle_grid, int column)
{
	int		index;
	char	visible;
	char	highest;

	index = 1;
	visible = '1';
	highest = puzzle_grid[index][column];
	while (index <= 4)
	{
		if (puzzle_grid[index][column] > highest)
		{
			highest = puzzle_grid[index][column];
			visible++;
		}
		index++;
	}
	if (puzzle_grid[0][column] == visible)
		return (check_bottom_clue(puzzle_grid, column));
	return (0);
}

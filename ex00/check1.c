/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiew <ktiew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:00:00 by ktiew             #+#    #+#             */
/*   Updated: 2026/07/25 13:00:06 by ktiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_right_clue(t_data *master, int row)
{
	int		index;
	char	visible;
	char	highest;

	index = master->size;
	visible = '1';
	highest = master->grid[row][index];
	while (index >= 1)
	{
		if (master->grid[row][index] > highest)
		{
			highest = master->grid[row][index];
			visible++;
		}
		index--;
	}
	return (master->clues[3][row - 1] == visible);
}

int	check_left_clue(t_data *master, int row)
{
	int		index;
	char	visible;
	char	highest;

	index = 1;
	visible = '1';
	highest = master->grid[row][index];
	while (index <= master->size)
	{
		if (master->grid[row][index] > highest)
		{
			highest = master->grid[row][index];
			visible++;
		}
		index++;
	}
	if (master->clues[2][row - 1] == visible)
		return (check_right_clue(master, row));
	return (0);
}

int	check_bottom_clue(t_data *master, int column)
{
	int		index;
	char	visible;
	char	highest;

	index = master->size;
	visible = '1';
	highest = master->grid[index][column];
	while (index >= 1)
	{
		if (master->grid[index][column] > highest)
		{
			highest = master->grid[index][column];
			visible++;
		}
		index--;
	}
	return (master->clues[1][column - 1] == visible);
}

int	check_top_clue(t_data *master, int column)
{
	int		index;
	char	visible;
	char	highest;

	index = 1;
	visible = '1';
	highest = master->grid[index][column];
	while (index <= master->size)
	{
		if (master->grid[index][column] > highest)
		{
			highest = master->grid[index][column];
			visible++;
		}
		index++;
	}
	if (master->clues[0][column - 1] == visible)
		return (check_bottom_clue(master, column));
	return (0);
}

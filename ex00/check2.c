/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiew <ktiew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:00:00 by ktiew             #+#    #+#             */
/*   Updated: 2026/07/25 13:00:06 by ktiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	check_no_duplicate(t_data *master, int row, int column, int digit)
{
	int	bit;

	bit = 1 << (digit - 1);
	if (master->row_masks[row] & bit)
		return (0);
	if (master->col_masks[column] & bit)
		return (0);
	return (1);
}

static int	row_visible_prefix(t_data *master, int row, int column)
{
	int		index;
	int		visible;
	char	highest;

	index = 0;
	visible = 1;
	highest = master->grid[row][0];
	while (index <= column)
	{
		if (master->grid[row][index] > highest)
		{
			highest = master->grid[row][index];
			visible++;
		}
		index++;
	}
	return (visible);
}

static int	column_visible_prefix(t_data *master, int row, int column)
{
	int		index;
	int		visible;
	char	highest;

	index = 0;
	visible = 1;
	highest = master->grid[0][column];
	while (index <= row)
	{
		if (master->grid[index][column] > highest)
		{
			highest = master->grid[index][column];
			visible++;
		}
		index++;
	}
	return (visible);
}

int	check_left_clue_partial(t_data *master, int row, int column)
{
	int	visible;
	int	clue;

	visible = row_visible_prefix(master, row, column);
	clue = master->clues[2][row] - '0';
	if (visible > clue)
		return (0);
	if (visible + (master->size - column - 1) < clue)
		return (0);
	return (1);
}

int	check_top_clue_partial(t_data *master, int row, int column)
{
	int	visible;
	int	clue;

	visible = column_visible_prefix(master, row, column);
	clue = master->clues[0][column] - '0';
	if (visible > clue)
		return (0);
	if (visible + (master->size - row - 1) < clue)
		return (0);
	return (1);
}

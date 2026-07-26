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

// static int	row_visible_prefix(t_data *master, int row, int column)
// {
// 	int	index;
// 	int	visible;
// 	char	highest;

// 	index = 0;
// 	visible = 1;
// 	highest = master->grid[row][0];
// 	while (index <= column)
// 	{
// 		if (master->grid[row][index] > highest)
// 		{
// 			highest = master->grid[row][index];
// 			visible++;
// 		}
// 		index++;
// 	}
// 	return (visible);
// }

// static int	column_visible_prefix(t_data *master, int row, int column)
// {
// 	int	index;
// 	int	visible;
// 	char	highest;

// 	index = 0;
// 	visible = 1;
// 	highest = master->grid[0][column];
// 	while (index <= row)
// 	{
// 		if (master->grid[index][column] > highest)
// 		{
// 			highest = master->grid[index][column];
// 			visible++;
// 		}
// 		index++;
// 	}
// 	return (visible);
// }

int	check_right_clue(t_data *master, int row)
{
	int		index;
	char	visible;
	char	highest;

	index = master->size - 1;
	visible = '1';
	highest = master->grid[row][index];
	while (index >= 0)
	{
		if (master->grid[row][index] > highest)
		{
			highest = master->grid[row][index];
			visible++;
		}
		index--;
	}
	return (master->clues[3][row] == visible);
}

int	check_left_clue(t_data *master, int row)
{
	int		index;
	char	visible;
	char	highest;

	index = 0;
	visible = '1';
	highest = master->grid[row][index];
	while (index < master->size)
	{
		if (master->grid[row][index] > highest)
		{
			highest = master->grid[row][index];
			visible++;
		}
		index++;
	}
	if (master->clues[2][row] == visible)
		return (check_right_clue(master, row));
	return (0);
}

// int	check_left_clue_partial(t_data *master, int row, int column)
// {
// 	int	visible;
// 	int	clue;

// 	visible = row_visible_prefix(master, row, column);
// 	clue = master->clues[2][row] - '0';
// 	if (visible > clue)
// 		return (0);
// 	if (visible + (master->size - column - 1) < clue)
// 		return (0);
// 	return (1);
// }

int	check_bottom_clue(t_data *master, int column)
{
	int		index;
	char	visible;
	char	highest;

	index = master->size - 1;
	visible = '1';
	highest = master->grid[index][column];
	while (index >= 0)
	{
		if (master->grid[index][column] > highest)
		{
			highest = master->grid[index][column];
			visible++;
		}
		index--;
	}
	return (master->clues[1][column] == visible);
}

int	check_top_clue(t_data *master, int column)
{
	int		index;
	char	visible;
	char	highest;

	index = 0;
	visible = '1';
	highest = master->grid[index][column];
	while (index < master->size)
	{
		if (master->grid[index][column] > highest)
		{
			highest = master->grid[index][column];
			visible++;
		}
		index++;
	}
	if (master->clues[0][column] == visible)
		return (check_bottom_clue(master, column));
	return (0);
}

// int	check_top_clue_partial(t_data *master, int row, int column)
// {
// 	int	visible;
// 	int	clue;

// 	visible = column_visible_prefix(master, row, column);
// 	clue = master->clues[0][column] - '0';
// 	if (visible > clue)
// 		return (0);
// 	if (visible + (master->size - row - 1) < clue)
// 		return (0);
// 	return (1);
// }

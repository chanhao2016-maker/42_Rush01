/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiew <ktiew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:00:00 by ktiew             #+#    #+#             */
/*   Updated: 2026/07/25 13:00:06 by ktiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_rush_solved(t_data *master, int column)
{
	column = 0;
	while (column < master->size)
	{
		if (!check_top_clue(master, column))
			return (0);
		column++;
	}
	print_solution(master);
	master->solved = 1;
	return (1);
}

int	rush_recursive(t_data *master, int row, int column)
{
	int	digit;

	if (row == master->size)
		return (is_rush_solved(master, column));
	if (column == master->size)
	{
		if (check_left_clue(master, row))
			return (rush_recursive(master, row + 1, 0));
		return (0);
	}
	digit = 1;
	while (digit <= master->size)
	{
		if (check_no_duplicate(master, row, column, digit))
		{
			master->grid[row][column] = digit + '0';
			if (rush_recursive(master, row, column + 1))
				return (1);
			master->grid[row][column] = '0';
		}
		digit++;
	}
	return (0);
}

void	rush(t_data *master)
{
	master->grid = create_grid(master->size);
	master->solved = 0;
	rush_recursive(master, 0, 0);
	if (master->solved == 0)
		print_error();
	free_memory(master->grid, master->size);
	free_memory(master->clues, MAX_DIRECTION);
}

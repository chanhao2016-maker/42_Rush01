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

static void	set_masks(t_data *master, int row, int column, int digit)
{
	int	bit;

	bit = 1 << (digit - 1);
	master->row_masks[row] |= bit;
	master->row_masks[row] = master->row_masks[row] | bit;
	master->col_masks[column] |= bit;
}

static void	unset_masks(t_data *master, int row, int column, int digit)
{
	int	bit;

	bit = 1 << (digit - 1);
	master->row_masks[row] &= ~bit;
	master->col_masks[column] &= ~bit;
}

static void	set_digit_order(t_data *master, int row, int *digit, int *step)
{
	if (master->clues[2][row] == '1')
	{
		*digit = master->size;
		*step = -1;
	}
	else if (master->clues[2][row] == master->size + '0')
	{
		*digit = 1;
		*step = 1;
	}
	else
	{
		*digit = 1;
		*step = 1;
	}
}

static int	check_fixed_clue(t_data *master, int row, int column, int digit)
{
	if (column == 0)
	{
		if (master->clues[2][row] == '1' && digit != master->size)
			return (0);
		if (master->clues[2][row] == master->size + '0' && digit != 1)
			return (0);
	}
	if (row == 0)
	{
		if (master->clues[0][column] == '1' && digit != master->size)
			return (0);
		if (master->clues[0][column] == master->size + '0' && digit != 1)
			return (0);
	}
	return (1);
}

// int	is_rush_solved(t_data *master, int column)
// {
// 	column = 0;
// 	while (column < master->size)
// 	{
// 		if (!check_top_clue(master, column))
// 			return (0);
// 		column++;
// 	}
// 	print_solution(master);
// 	master->solved = 1;
// 	return (1);
// }

int	rush_recursive(t_data *master, int row, int column)
{
	int	digit;
	int	step;

	if (row == master->size)
		return (is_rush_solved(master, column));
	if (column == master->size)
		return (is_rush_solved_2(master, row));
	set_digit_order(master, row, &digit, &step);
	while (digit >= 1 && digit <= master->size)
	{
		if (check_no_duplicate(master, row, column, digit)
			&& check_fixed_clue(master, row, column, digit))
		{
			master->grid[row][column] = digit + '0';
			set_masks(master, row, column, digit);
			if (check_left_clue_partial(master, row, column)
				&& check_top_clue_partial(master, row, column)
				&& rush_recursive(master, row, column + 1))
				return (1);
			unset_masks(master, row, column, digit);
			master->grid[row][column] = '0';
		}
		digit += step;
	}
	return (0);
}

// void	rush(t_data *master)
// {
// 	master->grid = create_grid(master->size);
// 	master->solved = 0;
// 	rush_recursive(master, 0, 0);
// 	if (master->solved == 0)
// 		print_error();
// 	free_memory(master->grid, master->size);
// 	free_memory(master->clues, MAX_DIRECTION);
// }

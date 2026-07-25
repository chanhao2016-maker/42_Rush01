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

void	solve_next_row(t_data *master, int row, int column)
{
	rush_recursive(master, row + 1, 1);
	if (row == master->size && check_top_clue(master, column))
		print_solution(master->grid);
}

void	rush_recursive(t_data *master, int row, int column)
{
	int	index;

	index = 1;
	while (index <= master->size && row <= master->size
		&& column <= master->size)
	{
		if (check_no_duplicate(master->grid, row, column, index))
		{
			master->grid[row][column] = index + '0';
			if (row == master->size && !check_top_clue(master, column))
				return ;
			if (column == master->size)
			{
				if (check_left_clue(master, row))
					solve_next_row(master, row, column);
			}
			else
				rush_recursive(master, row, column + 1);
		}
		index++;
	}
}

void	rush(t_data *master)
{
	master->grid = create_grid();
	put_clues(master->grid, master->clues);
	rush_recursive(master, 1, 1);
	if (master->grid[0][0] == '0')
		print_error();
	free_memory(master->grid, 6);
}

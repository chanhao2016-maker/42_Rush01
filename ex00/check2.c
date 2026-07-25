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

// int	check_no_duplicate(char **puzzle_grid, int row, int column, int index)
// {
// 	return (!check_column(puzzle_grid, row, column, index)
// 		&& !check_row(puzzle_grid, row, column, index));
// }

// int	check_row(char **puzzle_board, int row, int column, int digit)
// {
// 	int	index;

// 	index = 0;
// 	while (index < column)
// 	{
// 		if (puzzle_board[row][index] == digit + '0')
// 			return (1);
// 		index++;
// 	}
// 	return (0);
// }

// int	check_column(char **puzzle_board, int row, int column, int digit)
// {
// 	int	index;

// 	index = 0;
// 	while (index < row)
// 	{
// 		if (puzzle_board[index][column] == digit + '0')
// 			return (1);
// 		index++;
// 	}
// 	return (0);
// }

int	check_no_duplicate(t_data *master, int row, int column, int digit)
{
	int	index;

	index = 0;
	while (index < master->size)
	{
		if (master->grid[row][index] == digit + '0')
			return (0);
		if (master->grid[index][column] == digit + '0')
			return (0);
		index++;
	}
	return (1);
}

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

//if (argv[1][index] >= '1' && argv[1][index] <= '4' && index % 2 == 0)
int	is_valid_input(char **argv)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (argv[1][index])
	{
		if (argv[1][index] >= '1' && argv[1][index] <= '7' && index % 2 == 0)
			count++;
		else if (argv[1][index] == ' ')
			count++;
		index++;
	}
	if (check_above31_8(count))
		return (1);
	return (0);
}

int	check_no_duplicate(char **puzzle_grid, int row, int column, int index)
{
	return (!check_column(puzzle_grid, row, column, index)
		&& !check_row(puzzle_grid, row, column, index));
}

int	check_row(char **puzzle_board, int row, int column, int digit)
{
	int	index;

	index = 1;
	while (index < column)
	{
		if (puzzle_board[row][index] == digit + '0')
			return (1);
		index++;
	}
	return (0);
}

int	check_column(char **puzzle_board, int row, int column, int digit)
{
	int	index;

	index = 1;
	while (index < row)
	{
		if (puzzle_board[index][column] == digit + '0')
			return (1);
		index++;
	}
	return (0);
}

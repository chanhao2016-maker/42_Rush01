/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-jia- <hho-jia-@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:41:35 by hho-jia-          #+#    #+#             */
/*   Updated: 2025/03/09 18:41:41 by hho-jia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	solve_next_row(char **puzzle_grid, int row, int column)
{
	rush_recursive(puzzle_grid, row + 1, 1);
	if (row == 4 && check_top_clue(puzzle_grid, column))
		print_solution(puzzle_grid);
}

void	rush_recursive(char **puzzle_grid, int row, int column)
{
	int	index;

	index = 1;
	while (index <= 4 && row <= 4 && column <= 4)
	{
		if (is_valid_move(puzzle_grid, row, column, index))
		{
			puzzle_grid[row][column] = index + '0';
			if (row == 4 && !check_top_clue(puzzle_grid, column))
				return ;
			if (column == 4)
			{
				if (check_left_clue(puzzle_grid, row))
					solve_next_row(puzzle_grid, row, column);
			}
			else
				rush_recursive(puzzle_grid, row, column + 1);
		}
		index++;
	}
}

void	rush(char **clues)
{
	char	**puzzle_grid;

	puzzle_grid = create_grid();
	put_clues(puzzle_grid, clues);
	rush_recursive(puzzle_grid, 1, 1);
	if (puzzle_grid[0][0] == '0')
		print_error();
	free_memory(puzzle_grid, 6);
}

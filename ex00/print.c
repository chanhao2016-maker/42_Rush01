/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiew <ktiew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:00:00 by ktiew             #+#    #+#             */
/*   Updated: 2026/07/25 13:00:06 by ktiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_error(void)
{
	write(1, "Error\n", 6);
}

void	print_solution(char **puzzle_grid)
{
	int	index;
	int	j;

	index = 1;
	if (puzzle_grid[0][0] == '1')
		return ;
	puzzle_grid[0][0] = '1';
	while (index <= 4)
	{
		j = 1;
		while (j <= 4)
		{
			ft_putchar(puzzle_grid[index][j]);
			j++;
			if (j != 5)
				ft_putchar(' ');
		}
		ft_putchar('\n');
		index++;
	}
}

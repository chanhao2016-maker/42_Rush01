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

void	print_solution(t_data *master)
{
	int	index;
	int	j;

	index = 1;
	//if (master->grid[0][0] == '1')
	//	return ;
	master->grid[0][0] = '1';
	while (index <= master->size)
	{
		j = 1;
		while (j <= master->size)
		{
			ft_putchar(master->grid[index][j]);
			j++;
			if (j != master->size + 1)
				ft_putchar(' ');
		}
		ft_putchar('\n');
		index++;
	}
	write(1, "End\n", 4);
}

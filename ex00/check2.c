/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiew <ktiew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:50:17 by ktiew             #+#    #+#             */
/*   Updated: 2025/03/09 16:07:31 by ktiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_valid_input(char **argv)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (argv[1][index])
	{
		if (argv[1][index] >= '1' && argv[1][index] <= '4' && index % 2 == 0)
			count++;
		else if (argv[1][index] == ' ')
			count++;
		index++;
	}
	if (check_above31_8(count))
		return (1);
	return (0);
}

int	check_no_duplicate(t_data *master, int row, int column, int digit)
{
	int	index;

	index = 1;
	while (index < master->size)
	{
		if (master->grid[row][index] == digit + '0')
			return (1);
		if (master->grid[index][column] == digit + '0')
			return (1);
		index++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:34:49 by wchan-ha          #+#    #+#             */
/*   Updated: 2026/07/23 15:47:10 by wchan-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	logic_checking(int matrix[9][9], int input[9][9])
{
	int	count;
	int	max;
	int	x;
	int	y;

	y = 0;
	while (y < 9)
	{
		x = 0;
		max = 0;
		count = 0;
		while (x < 9)
		{
			if (matrix[y][x] > max)
			{
				max = matrix[y][x];
				count ++;
			}
			x ++;
		}
		if (count != input[2][y])
		{
			return (0);
		}
		max = 0;
		x = 8;
		count = 0;
		while (x >= 0)
		{
			if (matrix[y][x] > max)
			{
				max = matrix[y][x];
				count ++;
			}
			x --;
		}
		if (count != input[3][y])
		{
			return (0);
		}
		y ++;
	}
	x = 0;
	while (x < 9)
	{
		max = 0;
		y = 0;
		count = 0;
		while (y < 9)
		{
			if (matrix[y][x] > max)
			{
				max = matrix[y][x];
				count ++;
			}
			y++;
		}
		if (count != input[0][x])
		{
			return (0);
		}
		y = 8;
		count = 0;
		max = 0;
		while (y >= 0)
		{
			if (matrix[y][x] > max)
			{
				max = matrix[y][x];
				count ++;
			}
			y --;
		}
		if (count != input[1][x])
			return (0);
		x ++;
	}
	return (1);
}

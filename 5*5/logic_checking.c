/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.52kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 15:35:59 by wchan-ha          #+#    #+#             */
/*   Updated: 2026/06/21 16:09:37 by dsia-jun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	logic_checking(int matrix[5][5], int input[4][5])
{
	int	count;
	int	max;
	int	x;
	int	y;

	y = 0;
	while (y < 5)
	{
		x = 0;
		max = 0;
		count = 0;
		while (x < 5)
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
		x = 4;
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
	while (x < 5)
	{
		max = 0;
		y = 0;
		count = 0;
		while (y < 5)
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
		y = 4;
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

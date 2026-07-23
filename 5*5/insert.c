/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.52kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 15:37:53 by wchan-ha          #+#    #+#             */
/*   Updated: 2026/06/21 16:25:51 by wchan-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	logic_checking(int matrix[5][5], int input[4][5]);

int	check_noduplicate(int matrix[5][5], int y, int x, int val);

int	insert(int matrix[5][5], int input[4][5], int y, int x)
{
	int	val;

	if (y == 5)
	{
		return (logic_checking(matrix, input));
	}
	if (x == 5)
	{
		return (insert (matrix, input, y + 1, 0));
	}
	val = 1;
	while (val < 6)
	{
		if (check_noduplicate(matrix, y, x, val))
		{
			matrix[y][x] = val;
			if (insert(matrix, input, y, x + 1))
				return (1);
			matrix[y][x] = 0;
		}
		val ++;
	}
	return (0);
}

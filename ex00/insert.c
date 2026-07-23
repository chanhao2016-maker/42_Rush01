/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:37:53 by wchan-ha          #+#    #+#             */
/*   Updated: 2026/06/21 16:25:41 by wchan-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	logic_checking(int matrix[4][4], int input[4][4]);

int	check_noduplicate(int matrix[4][4], int y, int x, int val);

int	insert(int matrix[4][4], int input[4][4], int y, int x)
{
	int	val;

	if (y == 4)
	{
		return (logic_checking(matrix, input));
	}
	if (x == 4)
	{
		return (insert (matrix, input, y + 1, 0));
	}
	val = 1;
	while (val < 5)
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

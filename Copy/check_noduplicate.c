/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_noduplicate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:36:58 by wchan-ha          #+#    #+#             */
/*   Updated: 2026/07/23 15:45:14 by wchan-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	check_noduplicate(int matrix[9][9], int y, int x, int val)
{
	int	count;

	count = 0;
	while (count < 10)
	{
		if (matrix[y][count] == val)
			return (0);
		if (matrix[count][x] == val)
			return (0);
		count ++;
	}
	return (1);
}

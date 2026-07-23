/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_noduplicate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:36:58 by wchan-ha          #+#    #+#             */
/*   Updated: 2026/06/21 14:59:16 by dsia-jun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	check_noduplicate(int matrix[4][4], int y, int x, int val)
{
	int	count;

	count = 0;
	while (count < 4)
	{
		if (matrix[y][count] == val)
			return (0);
		if (matrix[count][x] == val)
			return (0);
		count ++;
	}
	return (1);
}

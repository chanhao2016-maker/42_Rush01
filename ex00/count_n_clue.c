/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_n_clue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 09:49:36 by wchan-ha          #+#    #+#             */
/*   Updated: 2026/07/24 14:48:32 by wchan-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	count_n_clue(char *s)
{
	int	total_length;
	int	n;

	total_length = ft_strlen(s);
	n = (total_length + 1) / 8;
	return (n);
}

int	check_above31_8(int count)
{
	int	i;

	i = 8;
	//while ((count != (31 + i)) && (count > (31 + i)))
	//	i *= 2;
	printf("count is %d\n", count);
	printf("i is %d\n", i);
	//if (count == 31 || count == (31 + i))
	if ((count + 1) % 8 == 0)
		return (1);
	return (0);
}

/*#include <stdio.h>
int	main(void)
{
	char *s3 = "1 2 3 6 2 3 1 2 3 1 2 3";
	char *s4 = "1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4";
	char *s5 = "1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5";
	char *s6 = "1 2 3 4 5 6 1 2 3 4 5 6 1 2 3 4 5 6 1 2 3 4 5 6";
	char *s7 = "1 2 3 4 5 6 7 1 2 3 4 5 6 7 1 2 3 4 5 6 7 1 2 3 4 5 6 7";
	char *s8 = "1 2 3 4 5 6 7 8 1 2 3 4 5 6 7 8 1 2 3 4 5 6 7 8 1 2 3 4 5 6 7 8";

	printf("3by3 = %d, l = %d\n", count_n_clue(s3), ft_strlen(s3));
	printf("4by4 = %d, l = %d\n", count_n_clue(s4), ft_strlen(s4));
	printf("5by5 = %d, l = %d\n", count_n_clue(s5), ft_strlen(s5));
	printf("6by6 = %d, l = %d\n", count_n_clue(s6), ft_strlen(s6));
	printf("7by7 = %d, l = %d\n", count_n_clue(s7), ft_strlen(s7));
	printf("8by8 = %d, l = %d\n\n", count_n_clue(s8), ft_strlen(s8));

	//is_valid_input -> count_checking
	printf("31 Return: %d\n", check_above31_8(31));
	printf("31 + 8 Return: %d\n", check_above31_8(31 + 8));
	printf("invalid Return: %d\n", check_above31_8(31 + 8 + 1));
	printf("invalid Return: %d\n", check_above31_8(31 + 2));
	printf("31 + double 8 return: %d\n", check_above31_8(31 + 8 + 8));
	printf("invalid Return: %d\n", check_above31_8(0));
}*/

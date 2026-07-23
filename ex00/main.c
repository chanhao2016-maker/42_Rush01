/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwei <yiwei@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:57:48 by yiwei             #+#    #+#             */
/*   Updated: 2025/03/09 18:57:59 by yiwei            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	char	**clues;

	if (argc == 1)
		print_error();
	else if (!is_valid_input(argv) || argc != 2)
		print_error();
	else
	{
		clues = save_clues(argv[1]);
		rush(clues);
		free_memory(clues, 4);
	}
	return (0);
}

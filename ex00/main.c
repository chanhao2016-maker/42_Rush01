/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiew <ktiew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:00:00 by ktiew             #+#    #+#             */
/*   Updated: 2026/07/25 13:00:06 by ktiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
int	main(int argc, char **argv)
{
	t_data	master;

	master = (t_data){0};
	if (argc == 1)
		print_error();
	else if (!is_valid_input(argv) || argc != 2)
		print_error();
	else
	{
		master.size = count_n_clue(argv[1]);
		master.clues = save_clues(argv[1], master.size);
		printf("Size is %d\n", master.size);
		rush(&master);
		free_memory(master.clues, master.size);
	}
	return (0);
}

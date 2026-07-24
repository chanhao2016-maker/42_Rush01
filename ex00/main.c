/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwei <yiwei@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:57:48 by yiwei             #+#    #+#             */
/*   Updated: 2026/07/24 14:47:32 by wchan-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
		master.clues = save_clues(argv[1]);
		rush(&master);
		free_memory(master.clues, master.size);
	}
	return (0);
}

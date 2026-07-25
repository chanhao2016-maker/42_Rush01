/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiew <ktiew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:00:00 by ktiew             #+#    #+#             */
/*   Updated: 2026/07/25 13:00:06 by ktiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>

# define MAX_DIRECTION 4

typedef struct s_data
{
	char	**grid;
	char	**clues;
	int		size;
	int		solved;
}	t_data;

void	ft_putchar(char c);
void	print_error(void);
void	print_solution(t_data *master);

void	free_memory(char **str, int rows);
char	**allocate_memory(int rows, int columns);
char	**create_grid(int size);
char	**save_clues(char *str, int size);

int		check_left_clue(t_data *master, int row);
int		check_top_clue(t_data *master, int column);
int		parser(t_data *master, char *str);
int		check_no_duplicate(t_data *master, int row, int column, int digit);

int		rush_recursive(t_data *master, int row, int column);
void	rush(t_data *master);

#endif

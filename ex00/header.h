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

typedef struct s_data
{
	char	**grid;
	char	**clues;
	int		size;
}	t_data;

void	ft_putchar(char c);
void	print_error(void);
void	print_solution(char **puzzle_grid);

void	free_memory(char **str, int rows);
char	**allocate_memory(int rows, int columns);
char	**create_grid(void);
void	put_clues(char **puzzle_grid, char **clues);
char	**save_clues(char *str);

int		check_left_clue(t_data *master, int row);
int		check_top_clue(t_data *master, int column);
int		check_above31_8(int count);
int		count_n_clue(char *s);
int		is_valid_input(char **argv);
int		check_no_duplicate(char **puzzle_grid, int row, int column, int index);
int		check_column(char **puzzle_board, int row, int column, int digit);
int		check_row(char **puzzle_board, int row, int column, int digit);

void	solve_next_row(t_data *master, int row, int column);
void	rush_recursive(t_data *master, int row, int column);
void	rush(t_data *master);

#endif

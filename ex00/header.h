/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-jia- <hho-jia-@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:16:44 by hho-jia-          #+#    #+#             */
/*   Updated: 2026/07/24 14:47:10 by wchan-ha         ###   ########.fr       */
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

int		check_left_clue(char **puzzle_board, int row);
int		check_top_clue(char **puzzle_board, int column);
int		check_above31_8(int count);
int		count_n_clue(char *s);
int		is_valid_input(char **argv);
int		is_valid_move(char **puzzle_grid, int row, int column, int index);
int		check_column(char **puzzle_board, int row, int column, int digit);
int		check_row(char **puzzle_board, int row, int column, int digit);

void	solve_next_row(t_data *master, int row, int column);
void	rush_recursive(t_data *master, int row, int column);
void	rush(t_data *master);

#endif

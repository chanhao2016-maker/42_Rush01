/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-jia- <hho-jia-@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:16:44 by hho-jia-          #+#    #+#             */
/*   Updated: 2025/03/09 18:55:17 by ktiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>

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
int		is_valid_input(char **argv);
int		is_valid_move(char **puzzle_grid, int row, int column, int index);
int		check_column(char **puzzle_board, int row, int column, int digit);
int		check_row(char **puzzle_board, int row, int column, int digit);

void	solve_next_row(char **puzzle_grid, int row, int column);
void	rush_recursive(char **puzzle_grid, int row, int column);
void	rush(char **clues);

#endif

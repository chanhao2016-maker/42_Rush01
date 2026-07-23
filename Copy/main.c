/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:06:58 by wchan-ha          #+#    #+#             */
/*   Updated: 2026/07/23 15:48:13 by wchan-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int     insert(int matrix[9][9], int input[9][9], int y, int x);
	
void    ft_print_int(int n)
{
    char        c;

    c = n + '0';
    write(1, &c, 1);
}

void    ft_print(char c)
{
    write(1, &c, 1);
}


int	main(int argc, char *argv[])
{
	int	i;
	int	matrix[9][9] = {0};
	int	input[9][9];
	int	a;
	int	b;
	int	x;
	int	y;
	
	argc = 2;
	i = 0;
	while(argv[1][i] != 0)
	{
			y = 0;
			while (y < 9)
			{
				x = 0;
				while (x < 9)
				{
					if (argv[1][i] != ' ')
					{
						input[y][x] = argv[1][i] - '0';
						x ++;
					}
					i++;
				}
				y ++;
				x = 0;
			}
			//input[y][x] = argv[1][i];
	}

	if (insert(matrix, input, 0, 0))
	    {
		a = 0;
		while (a < 9)
		{
		    b = 0;
		    while (b < 9)
		    {
			ft_print_int(matrix[a][b]);
			ft_print(' ');
			b ++;
		    }
		    ft_print('\n');
		    a ++;
		}
	    }

	    else
	    {
		ft_print('E');
		ft_print('r');
		ft_print('r');
		ft_print('o');
		ft_print('r');
		ft_print('\n');
	    }
}


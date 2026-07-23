/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.52kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:06:58 by wchan-ha          #+#    #+#             */
/*   Updated: 2026/06/21 18:31:00 by wchan-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int     insert(int matrix[5][5], int input[4][5], int y, int x);
	
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
	int	matrix[5][5] = {0};
	int	input[4][5];
	int	a;
	int	b;
	int	x;
	int	y;
	
	argc = 2;
	i = 0;
	while(argv[1][i] != 0)
	{
			y = 0;
			while (y < 4)
			{
				x = 0;
				while (x < 5)
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
	int ao;
	int bo;

	ao = 0;
	while (ao < 4)
	{
		bo = 0;
		while (bo < 5)
		{
			printf("%d ",input[ao][bo]);
			bo++;
		}
		printf("\n");
		ao++;
	}
	if (insert(matrix, input, 0, 0))
	    {
		a = 0;
		while (a < 5)
		{
		    b = 0;
		    while (b < 5)
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


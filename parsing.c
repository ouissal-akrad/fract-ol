/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:13:37 by ouakrad           #+#    #+#             */
/*   Updated: 2023/02/17 05:33:41 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	write(2, "-------------------------------Guide--------------------------------------\n", 76);
	write(2, "|                        You have 4 fractals :                           |\n", 76);
	write(2, "| Mandelbrot => ./fractol Mndelbrot                                      |\n", 76);
	write(2, "| Julia => ./fractol Julia 'real part' 'imaginary part'                  |\n", 76);
	write(2, "| Tricorn => ./fractol Tricorn                                           |\n", 76);
	write(2, "| Burning_ship => ./fractol Burning_ship                                 |\n", 76);
	write(2, "--------------------------------------------------------------------------\n", 76);
	exit(1);
}
void ft_init(t_fractol *p)
{
	p->color_code =  0xE7FE0000;
	p->max = 0;
	p->min = 0;
	p->coef = 1.0;
	p->width = 800.0;
	p->height = 800.0;
	p->x_trans = 0;
	p->y_trans = 0;
	p->MAX_ITERATIONS = 250;
	p->zoom = 2.0;
}

double	ft_map(int to_map, double max, double min ,double width, double x, double y)
{
	return (to_map * (max - min) /  width + min) - x - y;
}

void func(t_fractol *p ,int ac)
{
	if (ac == 4)
	{
		if (!ft_isdigit(p->tmp_av[2]) || !ft_isdigit(p->tmp_av[3]))
			ft_error();
		if(ft_strcmp(p->tmp_av[1],"Julia") == 0 && ft_strlen(p->tmp_av[1]) == 5)
			julia(p,p->tmp_av);
		else
			ft_error();
	}
	else if (ac == 2)
	{
		if(ft_strcmp(p->tmp_av[1],"Mandelbrot") == 0&& ft_strlen(p->tmp_av[1]) == 10)
			mandelbrot(p);
		else if(ft_strcmp(p->tmp_av[1],"Tricorn") == 0 && ft_strlen(p->tmp_av[1]) == 7)
			tricorn(p);
		else if((ft_strcmp(p->tmp_av[1],"Burning_ship") == 0) && (ft_strlen(p->tmp_av[1]) == 12))
			burning_ship(p);
		else
			ft_error();
	}
	else
		ft_error();
}


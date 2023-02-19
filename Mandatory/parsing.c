/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:13:37 by ouakrad           #+#    #+#             */
/*   Updated: 2023/02/19 20:16:08 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init(t_fractol *p)
{
	p->color_code = 0xE7FE0000;
	p->max = 0;
	p->min = 0;
	p->width = 900.0;
	p->height = 900.0;
	p->x_trans = 0;
	p->y_trans = 0;
	p->max_iterations = 250;
	p->zoom = 2.0;
	p->mlx = mlx_init();
	if (p->mlx == NULL )
		exit(1);
	p->img = mlx_new_image(p->mlx, p->width, p->height);
	if (p->img == NULL)
		exit(1);
	p->addr = mlx_get_data_addr(p->img, &p->bits_per_pixel,
			&p->line_length, &p->endian);
	if (p->addr == NULL)
		exit(1);
}

void	helper(t_fractol *p, int ac)
{
	p->y = 0;
	if (ac == 4)
		valid_julia(p, ac);
	else if (ac == 2)
	{
		if (ft_strcmp(p->tmp_av[1], "Mandelbrot") == 0
			&& ft_strlen(p->tmp_av[1]) == 10)
			mandelbrot(p);
		else
			ft_error();
	}
	else
		ft_error();
}

void	valid_julia(t_fractol *p, int ac)
{
	if (ac == 4)
	{
		if ((!ft_isdigit(p->tmp_av[2]) || !ft_isdigit(p->tmp_av[3])) && ac == 4)
			ft_error();
		if (ft_strcmp(p->tmp_av[1], "Julia") == 0
			&& ft_strlen(p->tmp_av[1]) == 5)
			julia(p, p->tmp_av);
		else
			ft_error();
	}
}

void	ft_error(void)
{
	write(1, "\033[0;36m|---------------------GUIDE---------------------|\n", 59);
	write(1, "\033[0;36m|                                               |\n", 59);
	write(1, "\033[0;36m|                 Available Sets :              |\n", 59);
	write(1, "\033[0;36m|                                               |\n", 59);
	write(1, "\033[0;36m|   Mandelbrot => ./fractol Mandelbrot          |\n", 59);
	write(1, "\033[0;36m|   Julia => ./fractol Julia 'x' 'yi'           |\n", 59);
	write(1, "\033[0;36m|                                               |\n", 59);
	write(1, "\033[0;36m|-----------------------------------------------|\n", 59);
	exit(1);
}

void	controls(void)
{
	write(1, "\033[0;35m|----------------CONTROLS--------------|\n", 50);
	write(1, "\033[0;35m|                                      |\n", 50);
	write(1, "\033[0;35m|   Scroll UP    : Zoom_In             |\n", 48);
	write(1, "\033[0;35m|   Scroll Down  : Zoom_Out            |\n", 48);
	write(1, "\033[0;35m|   ESC || Q     : QUIT                |\n", 48);
	write(1, "\033[0;35m|                                      |\n", 48);
	write(1, "\033[0;35m|--------------------------------------|\n", 48);
}

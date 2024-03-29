/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:10:56 by ouakrad           #+#    #+#             */
/*   Updated: 2023/02/18 05:44:17 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw(t_fractol *p)
{
	if (p->iteration == p->max_iterations)
		my_mlx_pixel_put(p, p->x, p->y, p->color_code);
	else
		my_mlx_pixel_put(p, p->x, p->y, p->color_code
			* (p->iteration + p->max_iterations));
}

void	mandelbrot(t_fractol *p)
{
	while (p->y < p->height)
	{
		p->x = 0;
		while (p->x < p->width)
		{
			p->zi = 0;
			p->zr = 0;
			p->cr = (p->x * ((p->max + p->zoom) - (p->min - p->zoom)) / p->width
					+ (p->min - p->zoom) - p->x_trans - 0);
			p->ci = (p->y * ((p->max + p->zoom) - (p->min - p->zoom)) / p->width
					+ (p->min - p->zoom) - 0 - p->y_trans);
			p->iteration = 0;
			while ((((p->zr * p->zr) + (p->zi * p->zi)) < 4.0)
				&& p->iteration < p->max_iterations)
			{
				p->zt = (p->zr * p->zr - p->zi * p->zi) + p->cr;
				p->zi = (2.0 * p->zr * p->zi) + p->ci;
				p->zr = p->zt;
				p->iteration++;
			}
			ft_draw(p);
			p->x++;
		}
		p->y++;
	}
}

void	julia(t_fractol *p, char *av[])
{
	while (p->y < p->height)
	{
		p->x = 0;
		while (p->x < p->width)
		{
			p->zr = (p->x * ((p->max + p->zoom) - (p->min - p->zoom)) / p->width
					+ (p->min - p->zoom) - p->x_trans - 0);
			p->zi = (p->y * ((p->max + p->zoom) - (p->min - p->zoom)) / p->width
					+ (p->min - p->zoom) - 0 - p->y_trans);
			p->cr = ft_atof(av[2]);
			p->ci = ft_atof(av[3]);
			p->iteration = 0;
			while (((p->zr * p->zr) + (p->zi * p->zi)) < 4.0
				&& p->iteration < p->max_iterations)
			{
				p->zt = (p->zr * p->zr - p->zi * p->zi) + p->cr;
				p->zi = (2.0 * p->zr * p->zi) + p->ci;
				p->zr = p->zt;
				p->iteration++;
			}
			ft_draw(p);
			p->x++;
		}
		p->y++;
	}
}

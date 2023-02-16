/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:10:56 by ouakrad           #+#    #+#             */
/*   Updated: 2023/02/16 02:40:40 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw(t_fractol *p)
{
	if (p->iteration == p->MAX_ITERATIONS)
		my_mlx_pixel_put(p, p->x, p->y, p->color_code);
	else
		my_mlx_pixel_put (p, p->x, p->y,p->color_code *(p->iteration + p->MAX_ITERATIONS));
}

void	mandelbrot(t_fractol *p)
{
	p->y = 0;
	while (p->y < 800)
	{
		p->x = 0;
		while (p->x < 800)
		{
			p->zi = 0;
			p->zr = 0;
			p->cr = ft_map(p->x,p->max + p->zoom ,p->min - p->zoom,p->height, p->x_trans, 0);
			p->ci = ft_map(p->y,p->max + p->zoom ,p->min - p->zoom, p->width, 0, p->y_trans);
			p->iteration = 0;
			while ((((p->zr * p->zr) + (p->zi * p->zi)) < 4.0)
				&& p->iteration < p->MAX_ITERATIONS)
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
	p->y = 0;
	while (p->y < 800)
	{
		p->x = 0;
		while (p->x < 800)
		{
			p->zi = ((p->y * 4) / 800) - 2;
			p->zr = ((p->x * 4) / 800) - 2;
			p->cr = ft_atof(av[2]);
			p->ci = ft_atof(av[3]);
			p->iteration = 0;
			while (((p->zr * p->zr) + (p->zi * p->zi))
				< 4.0 && p->iteration < p->MAX_ITERATIONS)
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

void	tricorn(t_fractol *p)
{
	p->y = 0;
	while (p->y < 800)
	{
		p->x = 0;
		while (p->x < 800)
		{
			p->zi = 0;
			p->zr = 0;
			p->cr = ft_map(p->x,p->max + p->zoom ,p->min - p->zoom,p->height, p->x_trans, 0);
			p->ci = ft_map(p->y,p->max + p->zoom ,p->min - p->zoom, p->width, 0, p->y_trans);
			p->iteration = 0;
			while (((p->zr * p->zr) + (p->zi * p->zi))
				< 4.0 && p->iteration < p->MAX_ITERATIONS)
			{
				p->zt = (p->zr * p->zr - p->zi * p->zi) + p->cr;
				p->zi = -((2.0 * p->zr * p->zi)) + p->ci;
				p->zr = p->zt;
				p->iteration++;
			}
			ft_draw(p);
			p->x++;
		}
		p->y++;
	}
}

void	burning_ship(t_fractol *p)
{
	p->y = 0;
	while (p->y < 800)
	{
		p->x = 0;
		while (p->x < 800)
		{
			p->zi = 0;
			p->zr = 0;
			p->cr = ft_map(p->x,p->max + p->zoom ,p->min - p->zoom,p->height, p->x_trans, 0);
			p->ci = ft_map(p->y,p->max + p->zoom ,p->min - p->zoom, p->width, 0, p->y_trans);
			p->iteration = 0;
			while (((p->zr * p->zr) + (p->zi * p->zi))
				<= 4.0 && p->iteration < p->MAX_ITERATIONS)
			{
				p->zt = (p->zr * p->zr - p->zi * p->zi) + p->cr;
				p->zi = (fabs(2.0 * p->zr * p->zi)) + p->ci;
				p->zr = p->zt;
				p->iteration++;
			}
			ft_draw(p);
			p->x++;
		}
		p->y++;
	}
}

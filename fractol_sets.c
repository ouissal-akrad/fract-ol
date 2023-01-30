/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:10:56 by ouakrad           #+#    #+#             */
/*   Updated: 2023/01/30 21:53:22 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mandelbrot(t_fractol *p)
{
	p->y = 0;

	while (p->y < 800)
	{
		p->x = 0;
		while(p->x < 800)
		{
			p->zi =0;
			p->zr =0;
			p->cr =((p->x * 4) / 800) - 2;
			p->ci =((p->y * 4) / 800) - 2;
			p->iteration = 0;
			while(((p->zr * p->zr) + (p->zi * p->zi)) < 4.0 && p->iteration < MAX_ITERATIONS)
			{
				p->zt =( p->zr * p->zr  - p->zi * p->zi )+ p->cr;
				p->zi = ((2 *p->zr * p->zi)) + p->ci;
				p->zr=	p->zt;
				p->iteration++;
			}
			if (p->iteration == MAX_ITERATIONS)
				my_mlx_pixel_put(p,p->x ,p->y,0x965D62);
			else
				my_mlx_pixel_put(p,p->x ,p->y,0xBA7967);
			p->x++;
		}
		p->y++;
	}
}

void Tricorn(t_fractol *p)
{
	p->y = 0;

	while (p->y < 800)
	{
		p->x = 0;
		while(p->x < 800)
		{
			p->zi =0;
			p->zr =0;
			p->cr =((p->x * 4) / 800) - 2;
			p->ci =((p->y * 4) / 800) - 2;
			p->iteration = 0;
			while(((p->zr * p->zr) + (p->zi * p->zi)) < 4.0 && p->iteration < MAX_ITERATIONS)
			{
				p->zt =( p->zr * p->zr  - p->zi * p->zi )+ p->cr;
				p->zi = -((2 *p->zr * p->zi)) + p->ci;
				p->zr=	p->zt;
				p->iteration++;
			}
			if (p->iteration == MAX_ITERATIONS)
				my_mlx_pixel_put(p,p->x ,p->y,0xFFFFFF);
			else
				my_mlx_pixel_put(p,p->x ,p->y,0xF1D4D4 * (p->iteration * MAX_ITERATIONS));
			p->x++;
		}
		p->y++;
	}
}

void burning_ship(t_fractol *p)
{
	p->y = 0;

	while (p->y < 800)
	{
		p->x = 0;
		while(p->x < 800)
		{
			p->zi =0;
			p->zr =0;
			p->cr =((p->x * 4) / 800) - 2;
			p->ci =((p->y * 4) / 800) - 2;
			p->iteration = 0;
			while(((p->zr * p->zr) + (p->zi * p->zi)) < 4.0 && p->iteration < MAX_ITERATIONS)
			{
				p->zt =( p->zr * p->zr  - p->zi * p->zi )+ p->cr;
				p->zi = (fabs(2 *p->zr * p->zi)) + p->ci;
				p->zr=	p->zt;
				p->iteration++;
			}
			if (p->iteration == MAX_ITERATIONS)
				my_mlx_pixel_put(p,p->x ,p->y,0xFFFFFF);
			else
				my_mlx_pixel_put(p,p->x ,p->y,0xFFFFFF * (p->iteration * MAX_ITERATIONS));
			p->x++;
		}
		p->y++;
	}
}

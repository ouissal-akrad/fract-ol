/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:15:38 by ouakrad           #+#    #+#             */
/*   Updated: 2023/02/08 17:46:17 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int ft_close_key(int keycode, t_fractol *f)
{
	if(keycode == 53)
	{
		mlx_destroy_image(f->mlx,f->img);
		mlx_destroy_window(f->mlx, f->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	ft_close_mouse( t_fractol *f)
{
	mlx_destroy_image(f->mlx,f->img);
	mlx_destroy_window(f->mlx, f->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	zoom(int keycode, int x, int y, t_fractol *f)
{
	(void) x;
	(void) y;
	if(keycode == 4)
	{
		mlx_clear_window(f->mlx,f->win);
		f->height *= 0.8;
		mandelbrot(f);
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	}
	if(keycode == 5)
	{
		mlx_clear_window(f->mlx,f->win);
		f->height /= 0.8;
		mandelbrot(f);
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	}
	return (0);
}


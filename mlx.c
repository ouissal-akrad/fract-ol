/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:15:38 by ouakrad           #+#    #+#             */
/*   Updated: 2023/02/06 22:57:47 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	keys(int keycode, int x, int y, t_fractol *f)
{
	(void) x;
	(void) y;
	if(keycode == 53)
	{
		mlx_destroy_image(f->mlx,f->img);
		mlx_destroy_window(f->mlx, f->win);
		exit(EXIT_SUCCESS);
	}
	if(keycode == 4)
	{
		f->max_r *= 2.0;
		mandelbrot(f);
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	}
	if(keycode == 5)
	{
		f->max_r /= 2.0;
		mandelbrot(f);
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
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
// void	zoom_out(t_fractol *f)
// {
// 	// double	center_r = 0;
// 	// double	center_i = 0;

// 	f->max_r *= 2.0;
// 	// printf("here\n");
// 	// f->min_r = -2.0;

// 	// f->max_i = 2.0;
// 	// f->min_i = -2.0;

// 	// center_r = f->min_r - f->max_r;
// 	// center_i = f->max_i - f->min_i;
// 	// f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
// 	// f->min_r = f->max_r + zoom * center_r;
// 	// f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
// 	// f->max_i = f->min_i + zoom * center_i;
// }

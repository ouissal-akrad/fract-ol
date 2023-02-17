/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:15:38 by ouakrad           #+#    #+#             */
/*   Updated: 2023/02/17 02:30:22 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void colors(t_fractol *f)
{
	f->color_code = f->color_code - (f->iteration - f->MAX_ITERATIONS);
}

int key_b(int keycode, t_fractol *f)
{
	if (keycode == 8)
		colors(f);
	if(keycode == 53 || keycode == 12)
	{
		mlx_destroy_image(f->mlx,f->img);
		mlx_destroy_window(f->mlx, f->win);
		exit(0);
	}
	if (keycode == KEY_UP)
		f->y_trans += 0.05;
	else if (keycode == KEY_DOWN)
		f->y_trans -= 0.05;
	else if (keycode == KEY_LEFT)
		f->x_trans += 0.05;
	else if (keycode == KEY_RIGHT)
		f->x_trans -= 0.05;
	mlx_clear_window(f->mlx,f->win);
	func(f,f->tmp_ac);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}

int	ft_close_mouse( t_fractol *f)
{
	mlx_destroy_image(f->mlx,f->img);
	mlx_destroy_window(f->mlx, f->win);
	exit(0);
	return (0);
}

int	zoom(int keycode,int x, int y, t_fractol *f)
{
	double cx;
	double cy;

	double newx;
	double newy;
	mlx_clear_window(f->mlx,f->win);
	cx = ft_map(x,f->max + f->zoom,f->min - f->zoom,f->height,0,0);
	cy = ft_map(y,f->max + f->zoom,f->min - f->zoom,f->height,0,0);
	if (keycode == 4)
	{
		f->zoom *= 1.1;
		f->iteration += 20;
	}
	if (keycode == 5)
	{
		f->zoom /= 1.1;
		f->iteration += 20;
	}
	newx = ft_map(x,f->max + f->zoom,f->min - f->zoom,f->height,0,0);
	newy = ft_map(y,f->max + f->zoom,f->min - f->zoom,f->height,0,0);
	f->x_trans += -cx + newx;
	f->y_trans += -cy + newy;
	func(f,f->tmp_ac);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return(0);
}

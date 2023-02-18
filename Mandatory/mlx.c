/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:15:38 by ouakrad           #+#    #+#             */
/*   Updated: 2023/02/18 06:10:30 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


int	key_b(int keycode, t_fractol *f)
{
	if (keycode == 53 || keycode == 12)
	{
		mlx_destroy_image (f->mlx, f->img);
		mlx_destroy_window(f->mlx, f->win);
		exit(0);
	}
	mlx_clear_window(f->mlx, f->win);
	helper(f, f->tmp_ac);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}

int	ft_close_mouse( t_fractol *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	exit(0);
	return (0);
}

int	zoom(int keycode, int x, int y, t_fractol *f)
{
	(void) x;
	(void) y;
	mlx_clear_window(f->mlx, f->win);
	if(keycode == ZOOM_IN)
		f->zoom *= 1.1;
	if(keycode == ZOOM_OUT)
		f->zoom /= 1.1;
	helper(f, f->tmp_ac);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}

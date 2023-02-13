/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:15:38 by ouakrad           #+#    #+#             */
/*   Updated: 2023/02/13 17:38:44 by ouakrad          ###   ########.fr       */
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
	double	w;
	double	h;

	w = (f->max_r - f->min_r) * STEP;
	h = (f->max_i - f->min_i) * STEP;

	if(keycode == 53)
	{
		mlx_destroy_image(f->mlx,f->img);
		mlx_destroy_window(f->mlx, f->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_UP)
	{
		// printf("here\n");
		f->max_i -= h;
		f->min_i -= h;
		mandelbrot(f);
	}
	else if (keycode == KEY_DOWN)
	{
		f->max_i += h;
		f->min_i += h;
	}
	else if (keycode == KEY_LEFT)
	{
		f->max_r -= w;
		f->min_r -= w;
	}
	else if (keycode == KEY_RIGHT)
	{
		f->max_r += w;
		f->min_r += w;
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

int zoom_key_code(int keycode, int x, int y, t_fractol *f)
{
	if(keycode == 4)
	{
		// f->MAX_ITERATIONS += 20;
		zoom(x,y,ZOOM_COEF,f);
	}
	if(keycode == 5)
	{
		// f->MAX_ITERATIONS -= 20;
		zoom(x,y,1.0 / ZOOM_COEF,f);
	}
	return 0;
}

void	zoom(int x, int y,double zoom, t_fractol *f)
{
	double cx;
	double cy;

	mlx_clear_window(f->mlx,f->win);
	cx = ft_map(x,f->width,f->min_r,f->max_r);
	cy = ft_map(y,f->width,f->min_i,f->max_i);
	f->max_r = (f->max_r - cx) / zoom;
	f->min_r = (f->min_r - cx) / zoom;
	f->max_i = (f->max_i - cy) / zoom;
	f->min_i = (f->min_i - cy) / zoom;
	printf("max_i:%f\tmax_i:%f\n", f->max_i,f->min_i );
	mandelbrot(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

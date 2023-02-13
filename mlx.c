/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:15:38 by ouakrad           #+#    #+#             */
/*   Updated: 2023/02/14 00:50:35 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void func(t_fractol *p)
{
	if(ft_strcmp(p->tmp_av[1],"Julia") == 0)
		julia(p,p->tmp_av);
	if(ft_strcmp(p->tmp_av[1],"Mandelbrot") == 0)
		mandelbrot(p);
	if(ft_strcmp(p->tmp_av[1],"Tricorn") == 0)
		Tricorn(p);
	if(ft_strcmp(p->tmp_av[1],"Burning_ship") == 0)
		burning_ship(p);
	// printf("%s | %s\n",p->tmp_av[1],p->tmp_av[2]);
}
void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void colors(t_fractol *f)
{
	f->color_code = f->color_code - (f->iteration - f->MAX_ITERATIONS);
	// printf("here%x\n", (f->iteration * f->MAX_ITERATIONS));
}
int key_b(int keycode, t_fractol *f)
{
	double	w;
	double	h;

	w = (f->max_r - f->min_r) * STEP;
	h = (f->max_i - f->min_i) * STEP;

	if (keycode == 8)
		colors(f);
	if(keycode == 53 || keycode == 12)
	{
		mlx_destroy_image(f->mlx,f->img);
		mlx_destroy_window(f->mlx, f->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_UP)
	{
		f->max_i -= h;
		f->min_i -= h;
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
	mlx_clear_window(f->mlx,f->win);
	func(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
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
		f->MAX_ITERATIONS += 20;
		zoom(x,y,ZOOM_COEF,f);
	}
	if(keycode == 5)
	{
		f->MAX_ITERATIONS -= 20;
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
	f->max_r = (f->max_r - cx) / zoom + cx;
	f->min_r = (f->min_r - cx) / zoom + cx;
	f->max_i = (f->max_i - cy) / zoom + cy;
	f->min_i = (f->min_i - cy) / zoom + cy;
	func(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

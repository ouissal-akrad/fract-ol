/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:55:18 by ouakrad           #+#    #+#             */
/*   Updated: 2023/02/06 22:58:04 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#define MAX_ITERATIONS 255

typedef struct fractol
{
	//pixels:
	double x;
	double y;
	//iteration:
	int iteration;
	//
	double	zr;
	double	zi;
	double min_r;
	double max_r;
	double min_i;
	double max_i;
	double 	zt;
	double 	ci;
	double 	cr;
	//MLX:
	void *mlx;
	void *win;
	//img
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_fractol;
//Prototype
void		mandelbrot(t_fractol *p);
void		Tricorn(t_fractol *p);
void		burning_ship(t_fractol *p);
void		julia(t_fractol *p, char *av[]);
int			ft_close_mouse( t_fractol *vars);
double		ft_atof(char *str);
int			ft_strcmp(char *s1, char *s2);
int			keys(int keycode,int x, int y, t_fractol *vars);
void		which_set(char *av[] , t_fractol *p);
void		my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
void		zoom_out(t_fractol *f);

//Lib
#include "libft/libft.h"
#include <mlx.h>
#include <stdio.h>
#include<math.h>
#endif

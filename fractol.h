/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:55:18 by ouakrad           #+#    #+#             */
/*   Updated: 2023/02/05 02:42:50 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#define MAX_ITERATIONS 250

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


void		mandelbrot(t_fractol *p);
void		Tricorn(t_fractol *p);
void		burning_ship(t_fractol *p);
void		julia(t_fractol *p, char *av[]);
int			ft_close(int keycode, t_fractol *vars);
double		ft_atof(char *str);
void		my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
#include "libft/libft.h"
#include <mlx.h>
#include <stdio.h>
#include<math.h>
#endif

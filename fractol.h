/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:55:18 by ouakrad           #+#    #+#             */
/*   Updated: 2023/02/08 18:03:58 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

# define MAX_ITERATIONS 250

typedef struct fractol
{
	//pixels:
	double x;
	double y;
	double width;
	double height;
	//iteration:
	int iteration;
	//
	double	zr;
	double	zi;
	double min_rr;
	double max_rr;
	double min_ri;
	double max_ri;
	double 	zt;
	double 	ci;
	double 	cr;
	//MLX:
	void *mlx;
	void *win;
	double x_tr;
	double y_tr;
	double min_i;
	double max_i;
	//img
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}t_fractol;

//////////////Sets//////////////////
void		mandelbrot(t_fractol *p);
void		Tricorn(t_fractol *p);
void		burning_ship(t_fractol *p);
void		julia(t_fractol *p, char *av[]);
/////////////Close/////////////////
int			ft_close_mouse( t_fractol *vars);
int			ft_close_key(int keycode, t_fractol *f);
/////////////Libft/////////////////
double		ft_atof(char *str);
int			ft_strcmp(char *s1, char *s2);
////////////Mlx////////////////////
void		my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
int			zoom(int keycode, int x, int y, t_fractol *f);
void		zoom_out(t_fractol *f);
//Lib
#include "libft/libft.h"
#include <mlx.h>
#include <stdio.h>
#include<math.h>
#endif

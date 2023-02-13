/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:55:18 by ouakrad           #+#    #+#             */
/*   Updated: 2023/02/13 17:08:40 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

# define STEP 10
# define ZOOM_COEF 0.5
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

typedef struct fractol
{
	//pixels:
	double x;
	double y;
	double width;
	double height;
	//iteration:
	int iteration;
	int MAX_ITERATIONS;
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

	double coef;

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
void		zoom(int x, int y,double zoom, t_fractol *f);
int			zoom_key_code(int keycode, int x, int y, t_fractol *f);
void		zoom_out(t_fractol *f);
double		ft_map(int to_map, int width, double min, double max);
//Lib
#include "libft/libft.h"
#include <mlx.h>
#include <stdio.h>
#include<math.h>
#endif

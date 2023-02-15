/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:55:18 by ouakrad           #+#    #+#             */
/*   Updated: 2023/02/15 17:08:40 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define STEP 0.02
# define ZOOM_COEF 0.05
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

typedef struct fractol
{
	double	x;
	double	y;
	double	width;
	double	height;
	int		color_code;

	int		iteration;
	int		MAX_ITERATIONS;

	double	zr;
	double	zi;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	zt;
	double	ci;
	double	cr;

	void	*mlx;
	void	*win;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	double	x_trans;
	double	y_trans;

	double	coef;
	char	**tmp_av;

}t_fractol;

//////////////Sets//////////////////
void		mandelbrot(t_fractol *p);
void		tricorn(t_fractol *p);
void		burning_ship(t_fractol *p);
void		julia(t_fractol *p, char *av[]);
/////////////Key-b && Mouse/////////////////
int			ft_close_mouse( t_fractol *vars);
int			key_b(int keycode, t_fractol *f);
/////////////Libft/////////////////
double		ft_atof(char *str);
int			ft_strcmp(char *s1, char *s2);
void		func(t_fractol *p);
////////////Mlx////////////////////
void		my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
void		zoom(int x, int y, double zoom, t_fractol *f);
int			zoom_key_code(int keycode, int x, int y, t_fractol *f);
double		ft_map(int to_map, int width, double min, double max,double x, double y);
void		colors(t_fractol *f);
void		ft_error(void);
void		ft_draw(t_fractol *p);
//Lib
# include "libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include<math.h>
#endif

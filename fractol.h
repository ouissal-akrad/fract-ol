/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:55:18 by ouakrad           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/02/18 02:34:58 by ouakrad          ###   ########.fr       */
=======
/*   Updated: 2023/02/17 05:04:59 by ouakrad          ###   ########.fr       */
>>>>>>> origin/master
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
<<<<<<< HEAD
//Lib
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include<math.h>
# include <stdlib.h>
=======
>>>>>>> origin/master

# define STEP 0.02
# define ZOOM_IN 4
# define ZOOM_OUT 5
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
	double	zoom;
	int		iteration;
<<<<<<< HEAD
	int		max_iterations;
=======
	int		MAX_ITERATIONS;
>>>>>>> origin/master

	double	zr;
	double	zi;
	double	min;
	double	max;
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

<<<<<<< HEAD
	char	**tmp_av;
	int		tmp_ac;
	double	cx;
	double	cy;

}t_fractol;

//---------------------------Sets---------------------------
void		ft_draw(t_fractol *p);
=======
	double	coef;
	char	**tmp_av;
	int		tmp_ac;
	double cx;
	double cy;

}t_fractol;

//////////////Sets//////////////////
>>>>>>> origin/master
void		mandelbrot(t_fractol *p);
void		tricorn(t_fractol *p);
void		burning_ship(t_fractol *p);
void		julia(t_fractol *p, char *av[]);
<<<<<<< HEAD
//----------------------------Mlx---------------------------
void		my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
int			ft_close_mouse( t_fractol *vars);
int			key_b(int keycode, t_fractol *f);
int			zoom(int keycode, int x, int y, t_fractol *f);
void		colors(t_fractol *f);
//-------------------------Libft-----------------------------
double		ft_atof(char *str);
double		ft_sign(char c);
int			ft_strcmp(char *s1, char *s2);
int			ft_strlen(const char *str);
int			ft_isdigit(char *av);
//-------------------------Pars-----------------------------
void		ft_init(t_fractol *p);
void		helper(t_fractol *p, int ac);
void		valid_julia(t_fractol *p, int ac);
void		ft_error(void);
void		controls(void);

=======
/////////////Key-b && Mouse/////////////////
int			ft_close_mouse( t_fractol *vars);
int			key_b(int keycode, t_fractol *f);
/////////////Libft/////////////////
double		ft_atof(char *str);
int			ft_strcmp(char *s1, char *s2);
void		func(t_fractol *p ,int ac);
void 		ft_init(t_fractol *p);
int			ft_strlen(const char *str);
int			ft_isdigit(char *av);
int			check(int c);
////////////Mlx////////////////////
void		my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
int			zoom(int keycode,int x, int y, t_fractol *f);
double		ft_map(int to_map, double max, double min ,double width, double x, double y);
void		colors(t_fractol *f);
void		ft_error(void);
void		ft_draw(t_fractol *p);

//Lib
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include<math.h>
# include <stdlib.h>
>>>>>>> origin/master
#endif

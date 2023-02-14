/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:13:37 by ouakrad           #+#    #+#             */
/*   Updated: 2023/02/14 19:20:25 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     ft_strcmp(char *s1, char *s2)
{
    int     i;

    i = 0;
    while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

double ft_atof(char *str)
{
    double sign = 1;
	double value;
    int i;
	int power;

    i = 0;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
    if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
    value = 0.0;
    while (ft_isdigit(str[i]))
	{
        value = value * 10.0 + (str[i] - '0');
        i++;
    }
    if (str[i] == '.')
        i++;
    power = 1.0;
    while (ft_isdigit(str[i]))
	{
        value = value * 10.0 + (str[i] - '0');
        power *= 10;
        i++;
    }
    return (sign * value / power);
}
double	ft_map(int to_map, int width, double min, double max,double x, double y)
{
	return (min + (max - min) * to_map / width) - x- y;
}
// void tt()
// {
// 	system("leaks fractol");
// }

int main(int ac, char *av[])
{
	// atexit(tt);
	t_fractol p;
	int i;
	i = 0;
	p.color_code =  0xE7FE0000;
	p.max_r = 2;
	p.min_r = -2;
	p.max_i = 2;
	p.min_i = -2;
	p.coef = 1.0;
	p.width = 800;
	p.height = 800;
	p.x_trans = 0;
	p.y_trans = 0;
	p.MAX_ITERATIONS = 250;
    p.mlx = mlx_init();
    p.win = mlx_new_window(p.mlx, p.width, p.height, "Fract-ol");
	p.img = mlx_new_image(p.mlx, p.width, p.height);
	p.addr = mlx_get_data_addr(p.img, &p.bits_per_pixel, &p.line_length,&p.endian);
	// if(ac != 2)
	// 	return(write(2,"ERROR !\n",9), 1);
	p.tmp_av = av;
	if(ac == 2)
	{
		if(ft_strcmp(av[1],"Mandelbrot") == 0)
			mandelbrot(&p);
		if(ft_strcmp(av[1],"Tricorn") == 0)
			Tricorn(&p);
		if(ft_strcmp(av[1],"Burning_ship") == 0)
			burning_ship(&p);
	}
	if(ac == 4 && (ft_strcmp(av[1],"Julia") == 0))
		julia(&p,av);
	mlx_put_image_to_window(p.mlx, p.win, p.img, 0, 0);
	mlx_key_hook(p.win,key_b, &p);
	mlx_mouse_hook(p.win,zoom_key_code,&p);
	mlx_hook(p.win, 17, 0, ft_close_mouse, &p);
    mlx_loop(p.mlx);
    return 0;
}

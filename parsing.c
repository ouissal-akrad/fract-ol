/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:13:37 by ouakrad           #+#    #+#             */
/*   Updated: 2023/02/05 02:34:58 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
int main(int ac, char *av[])
{
	t_fractol p;
	int i;
	i = 0;
    p.mlx = mlx_init();
    p.win = mlx_new_window(p.mlx, 800, 800, "Fract-ol");
	p.img = mlx_new_image(p.mlx, 800, 800);
	p.addr = mlx_get_data_addr(p.img, &p.bits_per_pixel, &p.line_length,&p.endian);
	// if(ac != 2)
	// 	return(write(2,"ERROR !\n",9), 1);
	if(ac == 2)
	{
		if(ft_strncmp(av[1],"Mandelbrot",11) == 0)
		{
			mandelbrot(&p);
		}
		if(ft_strncmp(av[1],"Tricorn",8) == 0)
			Tricorn(&p);
		if(ft_strncmp(av[1],"Burning_ship",13) == 0)
			burning_ship(&p);
	}
	if(ac == 4 && (ft_strncmp(av[1],"Julia",6) == 0))
	{
		julia(&p,av);
	}
	mlx_put_image_to_window(p.mlx, p.win, p.img, 0, 0);
	mlx_key_hook(p.win,ft_close,&p);
    // mlx_loop(p.mlx);
    return 0;
}
// }
// 	int		i;
// 	double	zr;
// 	double	zi;
// 	double 	ci;
// 	double 	cr;
// 	double	tmp_zi;
// 	i = 0;

// 	zr = 0;
// 	zi = 0;
// 	printf("%f | %f",zi , zr);
// 	if(ac != 2)
// 		return(write(2,"ERROR !\n",9), 1);
// 	if(ft_strncmp(av[1],"Jolia",6) == 0)
// 		write(1,"Jolia\n",7);
// 	else if(ft_strncmp(av[1],"Mandelbrot",11) == 0)
// 	{
// 		while (i < 50)
// 			{
// 				if ((zr * zr + zi * zi) > 4.0)
// 					break ;
// 				tmp_zi = 2 * zr * zi + ci;
// 				zr = zr * zr - zi * zi + cr;
// 				zi = tmp_zi;
// 				mlx_pixel_put(mlx, win, zi, zr, 0xFF0000);
// 				i++;
// 			}
// 	}

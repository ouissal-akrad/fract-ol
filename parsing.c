/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:13:37 by ouakrad           #+#    #+#             */
/*   Updated: 2023/02/02 22:18:56 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char *av[])
{
	t_fractol p;

    p.mlx = mlx_init();
    p.win = mlx_new_window(p.mlx, 800, 800, "Fract-ol");
	p.img = mlx_new_image(p.mlx, 800, 800);
	p.addr = mlx_get_data_addr(p.img, &p.bits_per_pixel, &p.line_length,&p.endian);
	if(ac != 2)
		return(write(2,"ERROR !\n",9), 1);
	if(ft_strncmp(av[1],"Mandelbrot",11) == 0)
	{
		mandelbrot(&p);
	}
	if(ft_strncmp(av[1],"Julia",6) == 0)
		julia(&p);
	if(ft_strncmp(av[1],"Tricorn",8) == 0)
		Tricorn(&p);
	if(ft_strncmp(av[1],"Burning_ship",13) == 0)
		burning_ship(&p);
	mlx_put_image_to_window(p.mlx, p.win, p.img, 0, 0);
	mlx_key_hook(p.win,ft_close,&p);
    mlx_loop(p.mlx);
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

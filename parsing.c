/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:13:37 by ouakrad           #+#    #+#             */
/*   Updated: 2023/02/17 01:18:15 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ftt_isdigit(char *av)
{
	int i;
	int c;
	i = 0;
	c = 0;
	if (av[0] == '-')
		i++;
	while (av[i])
	{
		if ((av[i] < '0' && av[i] > '9') && av[i] != '.')
			return (0);
		if (av[i] == '.')
			c++;
		i++;
	}
	if (c > 1)
		return 0;
	if (i == 1 && av[0] == '-')
		return 0;
	return (1);
}

double	ft_atof(char *str)
{
	double	sign;
	double	value;
	int		i;
	int		power;

	sign = 1.0;
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



void	ft_error(void)
{
	write(2, "-------------------------------Guide--------------------------------------\n", 76);
	write(2, "|                        You have 4 fractals :                           |\n", 76);
	write(2, "| Mandelbrot => ./fractol Mndelbrot                                      |\n", 76);
	write(2, "| Julia => ./fractol Julia 'real part' 'imaginary part'                  |\n", 76);
	write(2, "| Tricorn => ./fractol Tricorn                                           |\n", 76);
	write(2, "| Burning_ship => ./fractol Burning_ship                                 |\n", 76);
	write(2, "--------------------------------------------------------------------------\n", 76);
	exit(1);
}

void ft_init(t_fractol *p)
{
	p->color_code =  0xE7FE0000;
	p->max = 0;
	p->min = 0;
	p->coef = 1.0;
	p->width = 800.0;
	p->height = 800.0;
	p->x_trans = 0;
	p->y_trans = 0;
	p->MAX_ITERATIONS = 250;
	p->zoom = 2.0;
}

int main(int ac, char *av[])
{
	t_fractol p;
	int i;
	i = 0;

	ft_init(&p);
    p.mlx = mlx_init();
    p.win = mlx_new_window(p.mlx, p.width, p.height, "Fract-ol");
	p.img = mlx_new_image(p.mlx, p.width, p.height);
	p.addr = mlx_get_data_addr(p.img, &p.bits_per_pixel, &p.line_length,&p.endian);
	p.tmp_av = av;
	p.tmp_ac = ac;
	if(p.tmp_ac == 2 || p.tmp_ac == 4)
		func(&p ,p.tmp_ac);
	else
		ft_error();
	mlx_put_image_to_window(p.mlx, p.win, p.img, 0, 0);
	mlx_key_hook(p.win,key_b, &p);
	mlx_mouse_hook(p.win,zoom,&p);
	mlx_hook(p.win, 17, 0, ft_close_mouse, &p);
    mlx_loop(p.mlx);
    return 0;
}

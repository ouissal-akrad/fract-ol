/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:19:04 by ouakrad           #+#    #+#             */
/*   Updated: 2023/02/17 05:52:01 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char *av[])
{
	t_fractol p;
	int i;
	i = 0;

	ft_init(&p);
    p.mlx = mlx_init();
	if(p.mlx == NULL )
		exit(1);
    p.win = mlx_new_window(p.mlx, p.width, p.height, "Fract-ol");
	if(p.win == NULL)
		exit(1);
	p.img = mlx_new_image(p.mlx, p.width, p.height);
	if(p.img == NULL)
		exit(1);
	p.addr = mlx_get_data_addr(p.img, &p.bits_per_pixel, &p.line_length,&p.endian);
	if(p.addr == NULL)
		exit(1);
	p.tmp_av = av;
	p.tmp_ac = ac;
	if(ac == 2 || ac == 4)
		func(&p,p.tmp_ac);
	else
		ft_error();
	mlx_put_image_to_window(p.mlx, p.win, p.img, 0, 0);
	mlx_key_hook(p.win,key_b, &p);
	mlx_mouse_hook(p.win,zoom,&p);
	mlx_hook(p.win, 17, 0, ft_close_mouse, &p);
    mlx_loop(p.mlx);
    return 0;
}

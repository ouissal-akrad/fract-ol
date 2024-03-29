/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:19:04 by ouakrad           #+#    #+#             */
/*   Updated: 2023/02/19 20:14:27 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char *av[])
{
	t_fractol	p;

	ft_init(&p);
	p.tmp_av = av;
	p.tmp_ac = ac;
	if (ac == 2 || ac == 4)
	{
		helper(&p, p.tmp_ac);
		controls();
		p.win = mlx_new_window(p.mlx, p.width, p.height, "Fract-ol");
		if (p.win == NULL)
			exit(1);
	}
	else
		ft_error();
	mlx_put_image_to_window(p.mlx, p.win, p.img, 0, 0);
	mlx_key_hook(p.win, key_b, &p);
	mlx_mouse_hook(p.win, zoom, &p);
	mlx_hook(p.win, 17, 0, ft_close_mouse, &p);
	mlx_loop(p.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:17:24 by ouakrad           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/02/18 02:55:21 by ouakrad          ###   ########.fr       */
=======
/*   Updated: 2023/02/17 06:03:53 by ouakrad          ###   ########.fr       */
>>>>>>> origin/master
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

<<<<<<< HEAD
=======
int	check(int c)
{
	return (c >= '0' && c <= '9');
}

>>>>>>> origin/master
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_isdigit(char *av)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if ((av[0] == '-' || av[0] == '+') && av[1] != '\0')
		i++;
	while (av[i])
	{
		if (av[i] == '.')
		{
			i++;
			count++;
		}
		if ((!(av[i] >= '0' && av[i] <= '9')) || count >= 2)
			return (0);
		i++;
	}
	return (1);
}
<<<<<<< HEAD

double	ft_sign(char c)
{
	if (c == '-')
		return (-1);
	else if (c == '+')
		return (1);
	return (1);
}

=======
    
>>>>>>> origin/master
double	ft_atof(char *str)
{
	double	sign;
	double	value;
	int		i;
	int		power;

<<<<<<< HEAD
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = ft_sign(str[i++]);
	value = 0.0;
	while (str[i] >= '0' && str[i] <= '9')
=======
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
	while (check(str[i]))
>>>>>>> origin/master
	{
		value = value * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	power = 1.0;
<<<<<<< HEAD
	while (str[i] >= '0' && str[i] <= '9')
=======
	while (check(str[i]))
>>>>>>> origin/master
	{
		value = value * 10.0 + (str[i] - '0');
		power *= 10;
		i++;
	}
	return (sign * value / power);
}
<<<<<<< HEAD
=======

>>>>>>> origin/master

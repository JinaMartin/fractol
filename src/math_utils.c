/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:55:59 by mjina             #+#    #+#             */
/*   Updated: 2023/09/21 22:56:00 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	map(double unscaled_num, double new_min,
	double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	ret;

	ret.x = z1.x + z2.x;
	ret.y = z1.y + z2.y;
	return (ret);
}

t_complex	square_complex(t_complex z)
{
	t_complex	ret;

	ret.x = (z.x * z.x) - (z.y * z.y);
	ret.y = 2 * z.x * z.y;
	return (ret);
}

double	atodbl(char *s)
{
	long	num;
	double	fraction;
	double	pow;
	int		sign;

	num = 0;
	fraction = 0;
	sign = 1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		++s;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign *= -1;
	while (*s != '.' && *s)
		num = (num * 10) + (*s++ - 48);
	if (*s == '.')
		++s;
	while (*s)
	{
		pow /= 10;
		fraction = fraction + (*s++ - 48) * pow;
	}
	return ((num + fraction) * sign);
}

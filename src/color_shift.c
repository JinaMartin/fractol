/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:55:24 by mjina             #+#    #+#             */
/*   Updated: 2023/09/21 22:55:27 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

uint32_t	set_color(uint32_t i)
{
	t_color	color;	

	color.b = (uint8_t)(sin(0.2 * i) * 67 + 150);
	color.g = (uint8_t)(sin(0.3 * i + 2) * 97 + 100);
	color.r = (uint8_t)(sin(0.3 * i + 1) * 127 + 60);
	return (color.rgbt);
}

static uint32_t	insert_colors(uint32_t first_color,
	uint32_t second_color, float fmod_remainder)
{
	t_color	c1;
	t_color	c2;

	c1.r = (first_color >> 24) & 0xFF;
	c2.r = (second_color >> 24) & 0xFF;
	c1.g = (first_color >> 16) & 0xFF;
	c2.g = (second_color >> 16) & 0xFF;
	c1.b = (first_color >> 8) & 0xFF;
	c2.b = (second_color >> 8) & 0xFF;
	return ((uint32_t)(((c2.r - c1.r) * fmod_remainder) + c1.r) << 24 | \
			(uint32_t)(((c2.g - c1.g) * fmod_remainder) + c1.g) << 16 | \
			(uint32_t)(((c2.b - c1.b) * fmod_remainder) + c1.b) << 8 | 255);
}

uint32_t	color_management(t_complex *z, int i)
{
	double			log_of_z;
	uint32_t		first_color;
	uint32_t		second_color;

	log_of_z = log((z->x * z->x) + (z->y * z->y)) / 2;
	first_color = set_color(i);
	second_color = set_color(i + 1);
	return (insert_colors(first_color, second_color,
			fmod((i - (log(log_of_z / log(2)) / log(2))), 1)));
}

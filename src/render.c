/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:56:07 by mjina             #+#    #+#             */
/*   Updated: 2023/09/21 22:56:08 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	mandel_or_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!strncmp(fractal->name, "j", 1))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
		z->x = 0;
		z->y = 0;
	}
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	t_color		color_limit;

	color_limit = (t_color){.rgbt = 0x000000FF};
	i = 0;
	z.x = (map(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	mandel_or_julia(&z, &c, fractal);
	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			mlx_put_pixel(fractal->img, x, y, color_management(&z, i));
			return ;
		}
		i++;
	}
	mlx_put_pixel(fractal->img, x, y, color_limit.rgbt);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pixel(x, y, fractal);
	}
	mlx_image_to_window(fractal->mlx_window, fractal->img, 0, 0);
}

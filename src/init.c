/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:55:00 by mjina             #+#    #+#             */
/*   Updated: 2023/09/21 22:55:09 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_definition = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_window = mlx_init(WIDTH, HEIGHT, fractal->name, false);
	if (fractal->mlx_window == NULL)
	{
		puts(mlx_strerror(mlx_errno));
		free(fractal->mlx_window);
	}
	fractal->img = mlx_new_image(fractal->mlx_window, WIDTH, HEIGHT);
	if (fractal->img == NULL)
	{
		mlx_terminate(fractal->mlx_window);
		free(fractal->mlx_window);
	}
	data_init(fractal);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:55:33 by mjina             #+#    #+#             */
/*   Updated: 2023/09/21 22:55:34 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = param;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		fractal->shift_x -= 0.5 * fractal->zoom;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		fractal->shift_x += 0.5 * fractal->zoom;
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		fractal->shift_y += 0.5 * fractal->zoom;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		fractal->shift_y -= 0.5 * fractal->zoom;
	else if (keydata.key == MLX_KEY_RIGHT_SHIFT && keydata.action == MLX_PRESS)
		fractal->iterations_definition += 10;
	else if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_PRESS)
		fractal->iterations_definition -= 10;
	// else if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		// set_color(fractal);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_handler(fractal);
	fractal_render(fractal);
}

void	scroll_handler(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;

	fractal = param;
	fractal->scroll += ydelta;
	(void)xdelta;
	if (ydelta < 0)
		fractal->zoom *= 1.20;
	else if (ydelta > 0)
		fractal->zoom *= 0.80;
	else
		fractal->zoom = 1;
	fractal_render(fractal);
}

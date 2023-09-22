/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:55:46 by mjina             #+#    #+#             */
/*   Updated: 2023/09/21 22:55:48 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "m", 1))
		|| (argc == 4 && !ft_strncmp(argv[1], "j", 1)))
	{
		fractal.name = argv[1];
		if (argc == 4 && !ft_strncmp(argv[1], "j", 1))
		{
			fractal.julia_x = atodbl(argv[2]);
			fractal.julia_y = atodbl(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
	}
	else if (argv[1])
		input_error(argv[1]);
	else
		no_input();
	mlx_scroll_hook(fractal.mlx_window, scroll_handler, &fractal);
	mlx_key_hook(fractal.mlx_window, key_handler, &fractal);
	mlx_loop(fractal.mlx_window);
	mlx_terminate(fractal.mlx_window);
	return (EXIT_SUCCESS);
}

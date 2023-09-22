/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 00:27:40 by mjina             #+#    #+#             */
/*   Updated: 2023/09/22 00:27:42 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	close_handler(t_fractal *fractal)
{
	mlx_terminate(fractal->mlx_window);
	exit(EXIT_SUCCESS);
}

void	input_error(char *arg)
{
	if (!strncmp(arg, "j", 1))
		perror(JULIA_INPUTS);
	else
		perror(ERROR_MESSAGE);
	exit(EXIT_FAILURE);
}

void	no_input(void)
{
	perror(ERROR_MESSAGE);
	exit(EXIT_FAILURE);
}

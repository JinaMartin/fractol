#include "../fractol.h"

void key_handler(mlx_key_data_t keydata, void *param)
{
    t_fractal   *fractal;

    fractal = param;

    if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
        fractal->shift_x -= 0.2;
    else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
        fractal->shift_x += 0.2;
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
        fractal->shift_y += 0.2;
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
        fractal->shift_y -= 0.2;
    else if (keydata.key == MLX_KEY_RIGHT_SHIFT && keydata.action == MLX_PRESS)
        fractal->iterations_definition += 10;
	else if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_PRESS)
        fractal->iterations_definition -= 10;
	else if (keydata.key == MLX_KEY_RIGHT_ALT && keydata.action == MLX_PRESS)
        fractal->zoom *= 0.95;
	else if (keydata.key == MLX_KEY_LEFT_ALT && keydata.action == MLX_PRESS)
        fractal->zoom *= 1.05;
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        close_handler(fractal);
	fractal_render(fractal);
}

void	close_handler(t_fractal *fractal)
{
	mlx_terminate(fractal->mlx_window);
	exit(EXIT_SUCCESS);
}

// void	scroll_handler(double ydelta, void *param)
// {
// 	t_fractal	*fractal;

// 	fractal = param;
// 	if (ydelta > 0)
// 		fractal->zoom *= 1.05;
// 	else if (ydelta < 0)
// 		fractal->zoom *= 0.95;
// 	fractal_render(fractal);
// }
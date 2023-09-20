#include "../fractol.h"

void key_handler(mlx_key_data_t keydata, void *param)
{
    t_fractal   *fractal;

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
	//else if (keydata.key == MLX_KEY_RIGHT_ALT && keydata.action == MLX_PRESS)
    //    fractal->zoom *= 0.70;
	//else if (keydata.key == MLX_KEY_LEFT_ALT && keydata.action == MLX_PRESS)
    //    fractal->zoom *= 1.30;
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        close_handler(fractal);
	fractal_render(fractal);
}

void	close_handler(t_fractal *fractal)
{
	mlx_terminate(fractal->mlx_window);
	exit(EXIT_SUCCESS);
}

void	scroll_handler(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;

	fractal = param;
	fractal->scroll += ydelta;
	(void)xdelta;
	if (fractal->scroll > 0)
		fractal->zoom = fractal->scroll * 1.10;
	else if (fractal->scroll < 0)
		fractal->zoom = fractal->scroll * 0.90 * -1;
	printf("%f", fractal->scroll);
	fractal_render(fractal);
}

#include "../fractol.h"

int	main(int argc, char **argv)
{
	t_fractal		fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5))) 
		{
			fractal.name = argv[1];
			fractal.julia_x = atodbl(argv[2]);
			fractal.julia_y = atodbl(argv[3]);
			fractal_init(&fractal);
			fractal_render(&fractal);
			mlx_key_hook(fractal.mlx_window, key_handler, &fractal);
			// mlx_scroll_hook(fractal.mlx_window, scroll_handler, &fractal);
			mlx_loop(fractal.mlx_window);
		}
	else
		{
			ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
}
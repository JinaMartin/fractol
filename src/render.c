#include "../fractol.h"

static void	mandel_or_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!strncmp(fractal->name, "julia", 5))
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

// static uint32_t color_offset(int i, u_int32_t color, t_fractal *fractal)
// {
//     color = color - map(i, 0, 255, 0, fractal->iterations_definition);
//     return(color);
// }

static void handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex   z;
    t_complex   c;
    int         i;
    uint32_t	color;
    t_color     color_limit;

    color_limit = (t_color){.rgbt = 0x000000FF};
    i = 0;
    z.x = (map(x, -2, 2, 0, WIDTH) * fractal->zoom) + fractal->shift_x; // pixels scaled to fit
    z.y = (map(y, 2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
    mandel_or_julia(&z, &c, fractal);
    while (i < fractal->iterations_definition) //how many times to iterate the func
    {
        z = sum_complex(square_complex(z), c);
        if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
        {
            color = map(i, BLACK, MAGENTA_BURST, 0, (double)fractal->iterations_definition);
            // color = color_offset(i, color, fractal);
            mlx_put_pixel(fractal->img, x, y, color_management(&z, i));
            return;
        }
        i++;
    }
    mlx_put_pixel(fractal->img, x, y, WHITE);
}

void    fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            handle_pixel(x, y, fractal);
        }
    }
    mlx_image_to_window(fractal->mlx_window, fractal->img, 0, 0);
}
#include "../fractol.h"

//  z = z(sqr) + c
//  z is (0, 0)
//  c is actual point
/*
static void color_offset(int x, int y, mlx_image_t *img, int color)
{
    int offset;

    offset = (y * WIDTH) + (x * (sizeof(uint32_t) / 8));
   *(unsigned int *)(img->pixels + offset) = color;
}
*/
static void handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex   z;
    t_complex   c;
    int         i;
    uint32_t	color;

    i = 0;
    z.x = 0.0;
    z.y = 0.0;

    // pixels scaled to fit
    c.x = (map(x, -2, 2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
    c.y = (map(y, 2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
    //how many times to iterate the func
    while (i < fractal->iterations_definition)
    {
        z = sum_complex(square_complex(z), c);
        if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
        {
            color = map(i, BLACK, RED, 0, (double)fractal->iterations_definition);
            mlx_put_pixel(fractal->img, x, y, color);
            return;
        }
        i++;
    }
    mlx_put_pixel(fractal->img, x, y, GREEN);
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
#include "../fractol.h"
/*
void    set_color(t_fractal *fractal)
{
	if (fractal->col < 2)
    	fractal->col++;
	else
		fractal->col = 0;
	printf("%u", fractal->col);
	fractal_render(fractal);
}
*/

uint32_t	color_management(t_complex *z, int i)
{
	double			log_of_z;
	uint32_t		first_color;
	uint32_t		second_color;

	log_of_z = log((z->x * z->x) + (z->y * z->y)) / 2;
	first_color = set_color(i, color_option());
	second_color = set_color(i + 1, color_option());
	return (insert_colors(first_color, second_color, \
		fmod((i - (log(log_of_z / log(2)) / log(2))), 1)));
}

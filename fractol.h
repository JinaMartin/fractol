#ifndef FRACTOL_H
#define FRACTOL_H
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

#define ERROR_MESSAGE "Please enter \n\t\"./fractol m\" or \n\t\"./fractol j <value_1> <value_2>\"\n"
#define JULIA_INPUTS "Possible julia inputs:\n-0.79 0.15\n-0.169 1.04\n 0.3 -0.01\n-1.476 0\n-0.12 -0.77\n 0.28 + 0.008\n"

#define WIDTH	800
#define HEIGHT	800

#define BLACK	0x000000FF
#define WHITE	0xFFFFFFFF
#define RED		0xFF0000FF
#define GREEN	0x00FF00FF
#define BLUE	0x0000FFFF
#define GRAY	0x646464FF

//psych
#define MAGENTA_BURST		0xFF00FF00
#define MIDNIGHT_BLUE		0x071330FF
#define LIME_SHOCK			0xCCFF0000
#define NEON_ORANGE			0xFF660000
#define PSYCHADELIC_PURPLE	0x660066FF
#define AQUA_DREAM			0x33CCCCFF
#define HOT_PINK			0xFF66B2FF
#define ELECTRIC_BLUE		0x0066FFFF
#define LAVA_RED			0xFF3300FF

typedef union s_color
{
	uint32_t	rgbt;
	struct
	{
		uint8_t	r;
		uint8_t	g;
		uint8_t	b;
		uint8_t	t;
	};
}		t_color;

typedef struct	s_complex
{
    //	real
    double  x;
    //	i
    double  y;
}		t_complex;

typedef struct	s_fractal
{
	char		*name;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		scroll;
	double		julia_x;
	double		julia_y;
	// colors_t	col;
	mlx_image_t	*img;
	mlx_t		*mlx_window;
	double		escape_value;
	int			iterations_definition;//value  tight with image quality
}		t_fractal;

double  	atodbl(char *s);
void		input_error(char *arg);
void		scroll_handler(double xdelta, double ydelta, void *param);
void		close_handler(t_fractal *fractal);
void		key_handler(mlx_key_data_t keydata, void *param);
void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
void		no_input(void);
// uint32_t	set_color(uint32_t i);
double  	map(double unscaled_num, double new_min, double new_max, double old_max);
uint32_t	color_management(t_complex *z, int i);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

# endif
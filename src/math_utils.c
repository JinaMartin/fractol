#include "../fractol.h"

double  map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	ret;

	ret.x = z1.x + z2.x;
	ret.y = z1.y + z2.y;
	return (ret);
}

t_complex	square_complex(t_complex z)
{
	t_complex	ret;

	ret.x = (z.x * z.x) - (z.y * z.y);
	ret.y = 2 * z.x * z.y;
	return (ret);
}

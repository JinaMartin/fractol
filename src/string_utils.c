#include "../fractol.h"

double  atodbl(char *s)
{
    long	num;
    double	fraction;
    double	pow;
	int		sign;

	num = 0;
	fraction = 0;
	sign = 1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		++s;
	while (*s =='+' || *s == '-')
		if (*s++ == '-')
			sign *= -1;
	while (*s != '.' && *s)
		num = (num * 10) + (*s++ - 48);
	if (*s == '.')
		++s;
	while (*s)
	{
		pow /= 10;
		fraction = fraction + (*s++ - 48) * pow;
	}
	return ((num + fraction) * sign);
}
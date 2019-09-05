#include "basics.h"

int		ft_atoi(char *str)
{
	int result = 0, sign = 1;

	while (ft_isspace(*str))
		str++;
	while (*str == '-' || *str == '+')
		if(*str++ == '-')
			sign *= -1;
	while ('0' <= *str && *str <= '9')
		result = result * 10 + *str++ - '0';
	return result * sign;
}
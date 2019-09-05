#include "basics.h"

void	ft_putnbr(int nb)
{
	unsigned int n = (nb < 0) ? -nb : nb;
	char c = n % 10 + '0';

	if (nb < 0)
		write(1, "-", 1);
	if (n / 10)
		ft_putnbr(n / 10);
	write(1, &c, 1);
}
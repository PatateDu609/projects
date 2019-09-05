#include "basics.h"

int main(int ac, char **av)
{
	ft_putnbr(ft_atoi("\t\n\r\f\v                                    ---88979r654r8"));
	ft_putstr("\n");
	ft_putnbr(ft_isspace(' '));
	ft_putnbr(ft_isspace('\t'));
	ft_putnbr(ft_isspace('t'));
	ft_putnbr(ft_isspace('\v'));
	ft_putnbr(ft_isspace('\n'));
	ft_putnbr(ft_isspace('\r'));
	ft_putnbr(ft_isspace('\f'));
	ft_putstr("\n\n\n");
	ft_putstr("Hello World !\n");
	ft_putnbr(ft_strlen("Hello World !\n"));
	return (0);
}
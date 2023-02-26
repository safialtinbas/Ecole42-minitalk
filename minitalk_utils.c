/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltinba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:51:56 by saltinba          #+#    #+#             */
/*   Updated: 2023/01/31 14:51:57 by saltinba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		ft_putchar(str[index++]);
}

void	ft_putnbr(int nb)
{
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48);
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
}

int	ft_ascii_toint(char *str)
{
	int	index;
	int	num;

	index = 0;
	num = 0;
	while (str[index] != '\0')
	{
		num *= 10;
		num += str[index] - 48;
		index++;
	}
	return (num);
}

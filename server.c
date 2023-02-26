/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltinba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:31:21 by saltinba          #+#    #+#             */
/*   Updated: 2023/01/31 13:31:23 by saltinba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	catch_signal(int signal)
{
	static char	str = 0;
	static int	get_byte = 0;

	if (signal == SIGUSR1)
		str = str | 1;
	if (++get_byte == 8)
	{
		get_byte = 0;
		if (!str)
			ft_putstr("\n");
		write(1, &str, 1);
		str = 0;
	}
	else
		str <<= 1;
}

int	main(void)
{
	int	pid = getpid();
	ft_putstr("Server PID = ");
	ft_putnbr(pid);
	ft_putstr("\n");
	signal(SIGUSR1, catch_signal);
	signal(SIGUSR2, catch_signal);
	while (1)
	{
		pause();
	}
	return (0);
}

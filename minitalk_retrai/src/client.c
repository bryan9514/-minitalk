/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 07:54:30 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/08 09:48:42 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_signal(int pid, unsigned char c)
{
	int	mask;

	mask = 0b10000000;

	while (mask)
	{
		if (c & mask)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		mask >>= 1;
	}
}



int	check_args(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "Sintaxis is : ./client   <PID>   <message>\n", 44);
		return (0);
	}
	if (ft_atoi(av[1]) <= 0 || kill(ft_atoi(av[1]), 0) == -1)
	{
		write (1, "PIB not valide\n", 16);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	if (!check_args(ac, av))
		return (1);
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
		ft_send_signal(pid, av[2][i++]);
	ft_send_signal(pid, '\0');
	return (0);
}

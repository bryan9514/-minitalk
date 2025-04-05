/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:14:54 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/05 17:56:03 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_signal(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
		i--;
	}
}

void	confirm_signal(int	signal)
{
	// if (signal == SIGUSR2)
	// 	write (1, "1 ", 2);
	if (signal == SIGUSR1)
		write (1, "ok", 2);
	//write (1, "\n", 1);

}

int		main(int ac, char **av)
{
	int	i;
	int	pid;

	if (ac != 3)
	{
		write(1, "Sintaxis is : ./client   <PID>   <message>\n", 44);
		return (0);
	}
	pid = ft_atoi(av[1]);
	i = 0;
	signal(SIGUSR1, confirm_signal);
	while (av[2][i])
		ft_send_signal(pid, av[2][i++]);
	ft_send_signal(pid, '\0');
	return (0);
}

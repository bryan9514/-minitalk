/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:54:06 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/08 17:22:46 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_end = 0;

void	handle_ack(int sig)
{
	(void)sig;
}

void	ft_send_signal(int pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		pause();
		i--;
	}
}

void	confirm_signal(int signal)
{
	if (signal == SIGUSR2)
	{
		write (1, "✅ Transmission complete\n", 27);
		g_end = 1;
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
		write (1, "PID not valid\n", 16);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int					i;
	int					pid;
	struct sigaction	sa;

	if (!check_args(ac, av))
		return (1);
	pid = ft_atoi(av[1]);
	sa.sa_handler = &handle_ack;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	signal(SIGUSR2, &confirm_signal);
	i = 0;
	while (av[2][i])
		ft_send_signal(pid, av[2][i++]);
	ft_send_signal(pid, '\0');
	if (!g_end)
		pause();
	return (0);
}

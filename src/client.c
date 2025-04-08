/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 07:54:30 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/08 17:13:23 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		pause();
		i--;
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
		write (1, "PID not valid\n", 15);
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
	i = 0;
	while (av[2][i])
		ft_send_signal(pid, av[2][i++]);
	ft_send_signal(pid, '\0');
	return (0);
}

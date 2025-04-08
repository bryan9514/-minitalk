/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:14:54 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/07 15:09:04 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_waiting = 0;

// void	ft_send_signal(int pid, char c)
// {
// 	int	i;

// 	i = 7;
// 	while (i >= 0)
// 	{
// 		if (c & (1 << i))
// 			kill(pid, SIGUSR2);
// 		else
// 			kill(pid, SIGUSR1);
// 		usleep(1);
// 		i--;
// 	}
// }

void	ft_send_signal(int pid, char c)
{
	int i;
	char temp_c;

	i = 8;
	temp_c = c;
	while (i > 0)
	{
		i--;
		temp_c = c >> i;
		if (temp_c % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(1);
	}
}

void	confirm_signal(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signal == SIGUSR1)
	{
		write (1, "✅ Transmission complete\n", 27);
		g_waiting = 1;
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
	int					i;
	int					pid;
	struct sigaction	sa;

	if (!check_args(ac, av))
		return (1);
	pid = ft_atoi(av[1]);
	i = 0;
	sa.sa_sigaction = &confirm_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	while (av[2][i])
		ft_send_signal(pid, av[2][i++]);
	ft_send_signal(pid, 0);
	if (!g_waiting)
		pause();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:57:02 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/04 17:57:02 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_check = 0;

void	respond_clock(void)
{
	int	clock;

	clock = -1;
	while (g_check == 0 && ++clock < 10000)
		usleep(1);
	if (clock >= 10000)
	{
		ft_printf("\n\e[91mServer didn't respond.\nClient Closed.\n\n\e[97m");
		exit (0);
	}
}

void	change_state(int sig)
{
	(void)sig;
	g_check = 1;
}

void	confirm_msg(int sig)
{
	(void)sig;
	ft_printf("\n\e[92mServer has received the message.\n\n\e[97m");
}

void	send_signal(int pid, char c)
{
	int		i;
	char	temp_c;

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
		respond_clock();
		g_check = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
	{
		ft_printf("\n\e[91mError !\n");
		ft_printf("\e[92mCorrect Usage: %s <PID> <STR>\n\e[96m", av[0]);
		ft_printf("PID must be an unsigned int, and STR a char *.\n\n\e[97m");
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0 || kill(pid, 0))
	{
		ft_printf("\n\e[91mError !\n\e[92mNot a valid PID.\n");
		ft_printf("\e[96mPID must be an unsigned int. If the PID is ");
		ft_printf("already an unsigned int, then it is not active.\n\n\e[97m");
		return (0);
	}
	signal(SIGUSR1, change_state);
	signal(SIGUSR2, confirm_msg);
	i = -1;
	while (av[2][++i] && av[2])
		send_signal(pid, av[2][i]);
	send_signal(pid, 0);
	return (0);
}

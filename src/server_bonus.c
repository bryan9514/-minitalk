/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:18:18 by brturcio          #+#    #+#             */
/*   Updated: 2025/03/25 13:25:35 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

void	handle_bit_signal(int signal, siginfo_t *info, void *context)
{
	static int	c;
	static int	i;
	int			nb;

	(void)context;
	if (signal == SIGUSR2)
		nb = 1;
	else
		nb = 0;
	i++;
	c = (c << 1) + nb;
	if (i == 8)
	{
		if (c == END_TRANSMISSION)
			write (1 , "\n", 1);
		else
			write (1, &c, 1);
		c = 0;
		i = 0;
	}
	if (signal == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
	else if (signal == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handle_bit_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);


	pid_server();
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sleep(2);
	return (0);
}

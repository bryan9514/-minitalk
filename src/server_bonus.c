/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:54:15 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/08 13:47:30 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_bit_signal(int signal, siginfo_t *info, void *context)
{
	static t_str			*messages = NULL;
	static unsigned char	c;
	static int				bit_count;
	int						nb;

	(void)context;
	nb = (signal == SIGUSR2);
	c = (c << 1) + nb;
	bit_count++;
	if (bit_count == 8)
	{
		if (c == '\0')
		{
			printf_list(&messages);
			free_all(&messages);
			kill(info->si_pid, SIGUSR2);
		}
		else
			check_node(&messages, c);
		bit_count = 0;
		c = 0;
	}
	usleep(1);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset (&sa.sa_mask);
	sa.sa_sigaction = &handle_bit_signal;
	sa.sa_flags = SA_SIGINFO;
	pid_server();
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

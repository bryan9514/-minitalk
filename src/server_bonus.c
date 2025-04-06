/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:18:18 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/06 13:08:16 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_bit_signal(int signal, siginfo_t *info, void *context)
{
	static t_str	*messages = NULL;
	static int		c;
	static int		i;
	int				nb;

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
		{
			printf_list(&messages);
			free_all(&messages);
			kill(info->si_pid, SIGUSR1);
		}
		else
			add_node_char(&messages, c);
		c = 0;
		i = 0;
	}
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
		pause();
	return (0);
}

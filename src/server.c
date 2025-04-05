/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:39:35 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/05 17:42:29 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_bit_signal(int signal)
{
	static t_str	*messages = NULL;
	static char	c;
	static int	i;
	int			nb;

	if (signal == SIGUSR2)
		nb = 1;
	else
		nb = 0;
	i++;
	c = (c << 1) + nb;
	if (i == 8)
	{
		// write(1, &c, 1);
		if (c == END_TRANSMISSION)
		{
			printf_list(&messages);
			write (1, "\n", 1);
			free_all(&messages);
			// exit(0);
		}
		else
			add_node_char(&messages, c);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	pid_server();
	signal(SIGUSR1, handle_bit_signal);
	signal(SIGUSR2, handle_bit_signal);
	while (1)
		sleep(2);
	return (0);
}

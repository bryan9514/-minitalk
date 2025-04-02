/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:39:35 by brturcio          #+#    #+#             */
/*   Updated: 2025/03/24 16:01:21 by brturcio         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minitalk.h"

void	handle_bit_signal(int signal)
{
	static int	c;
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
		if (c == END_TRANSMISSION)
			write (1 , "\n", 1);
		else
			write (1, &c, 1);
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

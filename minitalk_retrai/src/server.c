/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 07:54:33 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/08 09:47:40 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_bit_signal(int signal)
{
	static unsigned char	c = 0;
	static int				mask = 0b10000000;
	static t_str			*messages = NULL;

	// (void)context;
	// (void)info;

	if (signal == SIGUSR1)
		c |= mask; // bit = 1 → guardamos en el lugar actual
	// si es SIGUSR2, dejamos el bit en 0 (por defecto)

	mask >>= 1;

	if (mask == 0)
	{
		if (c == '\0')
		{
			printf_list(&messages);
			free_all(&messages);
		}
		else
			check_node(&messages, c);
		c = 0;
		mask = 0b10000000; // reiniciamos para el siguiente carácter
	}
}


int	main(void)
{
	// struct sigaction	sa;

	// sigemptyset (&sa.sa_mask);
	// sa.sa_sigaction = &handle_bit_signal;
	// sa.sa_flags = SA_SIGINFO;
	ft_printf ("Server PID : %d\n", getpid());
	// sigaction(SIGUSR1, &sa, NULL);
	// sigaction(SIGUSR2, &sa, NULL);
	signal(SIGUSR1, handle_bit_signal);
	signal(SIGUSR2, handle_bit_signal);
	while (1)
		pause();
	return (0);
}

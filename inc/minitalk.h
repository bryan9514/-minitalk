/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:12:25 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/06 21:58:27 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define END_TRANSMISSION '\0'
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

typedef struct s_str
{
	char			c;
	struct s_str	*next;
}	t_str;

int		ft_atoi(const char *nptr);
void	ft_putnbr(int nb);
void	pid_server(void);
int		add_node_char(t_str **node, char c);
void	printf_list(t_str **node);
void	free_all(t_str **node);

#endif

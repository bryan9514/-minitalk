/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:12:25 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/08 16:28:26 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

typedef struct s_str
{
	char			c;
	struct s_str	*next;
}	t_str;

int		ft_atoi(const char *nptr);
int		add_node_char(t_str **node, char c);
void	ft_putnbr(int nb);
void	pid_server(void);
void	printf_list(t_str **node);
void	free_all(t_str **node);
void	check_node(t_str **menssages, char c);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:12:25 by brturcio          #+#    #+#             */
/*   Updated: 2025/03/24 13:35:35 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H


#define END_TRANSMISSION '\0'
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int		ft_atoi(const char *nptr);
void	ft_putnbr(int nb);
void	pid_server(void);



#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:55:31 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/05 17:06:24 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	add_node_char(t_str **node, char c)
{
	t_str	*new_node;
	t_str	*last_node;

	new_node = malloc(sizeof(t_str));
	if(!new_node)
		return (0);
	new_node->c = c;
	new_node->next = NULL;
	if (*node == NULL)
		*node = new_node;
	else
	{
		last_node = *node;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
	}
	return (1);
}

void	free_all(t_str **node)
{
	t_str	*tmp;

	while (*node)
	{
		tmp = (*node)->next;
		free(*node);
		*node = tmp;
	}
}

void	printf_list(t_str **node)
{
	t_str	*tmp;

	tmp = *node;
	while (tmp != NULL)
	{
		write (1, &tmp->c, 1);
		tmp = tmp->next;
	}

}






/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:45:39 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/29 14:59:07 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_malloc.h"

void	*malloc_t(size_t size)
{
	t_link	*new;

	new = (t_link *)malloc(sizeof(t_link));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->data = malloc(size);
	if (!new->data)
		return (free(new), NULL);
	link_append(new);
	return (new->data);
}

void	free_t(void *ptr)
{
	link_rm(ptr);
	free(ptr);
}

void	free_t_bad(void *ptr)
{
	t_link	*list;
	t_link	*prev;

	list = *get_head();
	if (!list)
		return ;
	if (list->data == ptr)
	{
		*get_head() = list->next;
		free(list);
		return (free(ptr));
	}
	prev = list;
	list = list->next; 
	while (list)
	{
		if (list->data == ptr)
		{
			prev->next = list->next;
			free(list);
			return ;
		}
		prev = list;
		list = list->next;
	}
}
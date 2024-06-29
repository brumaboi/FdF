/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_bad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:47:11 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/29 14:59:43 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_malloc.h"

void	fail_t(int nbr)
{
	*get_bad() = nbr;
}

void	*malloc_t_bad(size_t size)
{
	t_link	*new;

	if (*get_bad() == 0)
	{
		*get_bad() = -1;
		return (NULL);
	}
	new = (t_link *)malloc(sizeof(t_link));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->data = malloc(size);
	if (!new->data)
		return (free(new), NULL);
	link_append(new);
	if (*get_bad() >= 0)
		*get_bad() = *get_bad() - 1;
	return (new->data);
}
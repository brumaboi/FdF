/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:48:44 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/29 14:59:28 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_malloc.h"

t_link	**get_head(void)
{
	static t_link	*head = NULL;

	return (&head);
}

int	*get_bad(void)
{
	static int	bad = -1;

	return (&bad);
}
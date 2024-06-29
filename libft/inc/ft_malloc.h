/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:46:28 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/29 14:58:28 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_link
{
	void			*data;
	struct s_link	*next;
}   t_link;

int		*get_bad(void);
int		leak_size(void);
void	link_free();
void	fail_t(int nbr);
void	free_t(void *ptr);
void	free_t_bad(void *ptr);
void	link_rm(void *ptr);
void	*malloc_t(size_t size);
void	link_append(t_link *new);
void	*malloc_t_bad(size_t size);
t_link	**get_head(void);

#endif
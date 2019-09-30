/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 01:58:38 by sapark            #+#    #+#             */
/*   Updated: 2019/08/31 13:38:54 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memalloc_chr(size_t size, char c)
{
	void	*res;

	if (!(res = (void *)malloc(sizeof(void) * size + 1)))
		return (NULL);
	ft_memset(res, c, size);
	return (res);
}

void	insertnode(t_pf *pf, char *res)
{
	t_res	*tmp;
	t_res	*new_node;

	new_node = (t_res *)malloc(sizeof(t_res));
	tmp = pf->head;
	new_node->res = ft_strdup(res);
	new_node->next = NULL;
	if (!tmp)
		pf->head = new_node;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

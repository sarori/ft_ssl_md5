/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:17:45 by sapark            #+#    #+#             */
/*   Updated: 2019/09/24 22:17:56 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_elem(char *res, char *str, int start, int size)
{
	int	i;

	i = 0;
	while (size--)
		res[start++] = str[i++];
	return (res);
}

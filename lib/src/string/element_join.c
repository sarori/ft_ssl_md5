/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:18:30 by sapark            #+#    #+#             */
/*   Updated: 2019/09/24 22:18:44 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*element_join(char *res, char *s1, char *s2)
{
	unsigned int	len1;
	unsigned int	len2;

	if (!s1 || !s2)
		return (NULL);
	ft_strcpy(res, s1);
	ft_strcat(res, s2);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	return (res);
}

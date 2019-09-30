/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scjoin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:16:14 by sapark            #+#    #+#             */
/*   Updated: 2019/09/29 18:58:55 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_scjoin(char *s1, char c, int mfree)
{
	char			*res;
	unsigned int	len1;
	int				i;

	if (!c)
		return (s1);
	len1 = !s1 ? 0 : ft_strlen(s1);
	if (!(res = (char *)malloc(sizeof(char) * (len1 + 2))))
		return (NULL);
	res[len1 + 1] = '\0';
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = c;
	if (s1 && mfree)
		free(s1);
	return (res);
}

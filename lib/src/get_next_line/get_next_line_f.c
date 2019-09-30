/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 23:51:41 by sapark            #+#    #+#             */
/*   Updated: 2019/09/28 23:51:59 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_next_line_f(int fd, char **file)
{
	char	*buf;
	char	*str;
	char	*tmp;
	int		gnl;

	buf = NULL;
	str = NULL;
	while ((gnl = get_next_line(fd, &buf)) > 0)
	{
		if (str)
		{
			tmp = ft_strjoin_by(str, buf, "\n");
			free(str);
			str = ft_strdup(tmp);
			free(tmp);
		}
		else
			str = ft_strdup(buf);
		free(buf);
	}
	if (gnl < 0)
		return (-1);
	*file = strdup(str);
	free(str);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 23:31:17 by sapark            #+#    #+#             */
/*   Updated: 2019/09/29 01:03:00 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	error_case(int code, char *input)
{
	if (code == ERROR_INPUT)
		ft_printf("ft_ssl: %s: No such file or directory\n", input);
	else if (code == ERROR_FOLDER)
		ft_printf("ft_ssl: %s: Is a directory\n");
}

void	error_exit(int code, char *input)
{
	int i;

	i = -1;
	if (code == ERROR_USAGE)
		ft_printf("usage: ft_ssl command [command opts] [command args]");
	else if (code == ERROR_COMMAND)
	{
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\n", input);
		ft_printf("Standard commands:\n\nMessage Digest commands:\n");
		while (g_ssl_dp[++i].command)
			ft_printf("%s\n", g_ssl_dp[i].command);
	}
	else if (code == ERROR_FLAG)
	{
		ft_printf("ft_ssl: illegal option -- %s\n", input);
		ft_printf("usage: ft_ssl [-pqr] [-s string] [files ...]");
	}
	exit(-1);
}

void	reverse_bits(uint *c)
{
	uint t;

	t = 0;
	t += *c & 0xff;
	t = t << 8;
	t += (*c >> 8) & 0xff;
	t = t << 8;
	t += (*c >> 16) & 0xff;
	t = t << 8;
	t += (*c >> 24) & 0xff;
	*c = t;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 23:31:13 by sapark            #+#    #+#             */
/*   Updated: 2019/09/29 02:18:56 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int	main(int ac, char *av[])
{
	t_ssl	ssl;
	int		i;

	if (ac == 1)
		error_exit(ERROR_USAGE, NULL);
	ssl.dp = g_ssl_dp[command(av[1])];
	i = 2;
	ssl.is_file_read = 0;
	while (av[i] && av[i][0] == '-' && (*(av[i] + 1) != 's'))
		flag_handle(*(av[i++] + 1), &ssl, &ac);
	handle_input(i, ac, av, &ssl);
	return (0);
}

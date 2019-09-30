/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 23:31:15 by sapark            #+#    #+#             */
/*   Updated: 2019/09/29 19:29:19 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		command(char *cmd)
{
	int i;

	i = -1;
	while (g_ssl_dp[++i].command)
		if (ft_strcmp(g_ssl_dp[i].command, cmd) == 0)
			break ;
	if (!g_ssl_dp[i].command)
		error_exit(ERROR_COMMAND, cmd);
	return (i);
}

void	flag_handle(char c, t_ssl *ssl, int *ac)
{
	static int cnt = 0;

	if (cnt++ == 0)
	{
		ssl->flags.p = 0;
		ssl->flags.q = 0;
		ssl->flags.r = 0;
	}
	if (c == 'p')
		ssl->flags.p = 1;
	else if (c == 'q')
		ssl->flags.q = 1;
	else if (c == 'r')
		ssl->flags.r = 1;
	if (ssl->flags.r && ssl->flags.q)
		ssl->flags.r = 0;
	*ac -= 1;
}

void	case_stdin(int ac, t_ssl *ssl)
{
	char *input;
	char *tmp;

	if (ssl->flags.p || ac == 2)
	{
		if (get_next_line(0, &tmp) > 0)
		{
			input = ft_strjoin(tmp, "\n");
			free(tmp);
			ssl->flags.p ? ft_printf("%s", input) : 0;
			ssl->dp.f(input);
			ft_printf("\n");
			free(input);
		}
	}
}

void	case_file(int fd, t_ssl *ssl, char *file)
{
	char *input;
	char *tmp;

	if (get_next_line_f(fd, &tmp) >= 0)
	{
		input = ft_strjoin(tmp, "\n");
		free(tmp);
		tmp = ft_strdup(ssl->dp.command);
		!ssl->flags.q && !ssl->flags.r ? ft_printf("%s(%s)= ",
		ft_str_toupper(tmp), file) : 0;
		ssl->dp.f(input);
		ssl->flags.r ? ft_printf(" %s", file) : 0;
		ft_printf("\n");
		free(input);
		free(tmp);
		ssl->is_file_read = 1;
	}
	else
		error_case(ERROR_FOLDER, file);
	close(fd);
}

void	handle_input(int i, int ac, char *av[], t_ssl *ssl)
{
	char	*tmp;
	int		fd;

	case_stdin(ac, ssl);
	while (av[i])
	{
		if (ssl->is_file_read == 0 && ft_strcmp(av[i], "-s") == 0)
		{
			tmp = ft_strdup(ssl->dp.command);
			if (!ssl->flags.q && !ssl->flags.r)
				ft_printf("%s (\"%s\") = ", ft_str_toupper(tmp), av[++i]);
			else
				i++;
			ssl->dp.f(av[i]);
			ssl->flags.r ? ft_printf(" %s", av[i]) : 0;
			ft_printf("\n");
			free(tmp);
		}
		else if ((fd = open(av[i], O_RDONLY)) > 0)
			case_file(fd, ssl, av[i]);
		else
			error_case(ERROR_INPUT, av[i]);
		i++;
	}
}

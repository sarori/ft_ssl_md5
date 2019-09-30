/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 23:35:49 by sapark            #+#    #+#             */
/*   Updated: 2019/09/29 19:06:04 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../lib/includes/ft_printf.h"
# include "../lib/includes/libft.h"

# define ERROR_FOLDER -9
# define ERROR_INPUT -10
# define ERROR_FLAG -11
# define ERROR_USAGE -12
# define ERROR_COMMAND -13

# define BIT_SIZE 8

# define L_LOTATION(n, d) ((n << d) | (n >> (32 - d)))
# define R_ROTATION(n, d) ((n >> d) | (n << (32 - d)))
# define R_ROTATION_64(n, d) ((n >> d) | (n << (64 - d)))

typedef	struct	s_flags
{
	int			p;
	int			q;
	int			r;
}				t_f;

typedef struct	s_ssl_dp
{
	char		*command;
	void		(*f)(char *);
}				t_sdp;

typedef struct	s_ssl
{
	t_sdp		dp;
	t_f			flags;
	int			is_file_read;
}				t_ssl;

typedef struct	s_md
{
	uint		a_;
	uint		b_;
	uint		c_;
	uint		d_;
	uint		a;
	uint		b;
	uint		c;
	uint		d;
	uint		f;
	uint		g;
	u_char		*n;
	u_char		m[16][4];
	uint		set;
}				t_md;

typedef struct	s_sha
{
	uint		h_[8];
	uint		a;
	uint		b;
	uint		c;
	uint		d;
	uint		e;
	uint		f;
	uint		g;
	uint		h;
	u_char		*n;
	uint		w[64];
	uint		set;
}				t_sha;

typedef struct	s_sha5
{
	uint64_t	h_[8];
	uint64_t	a;
	uint64_t	b;
	uint64_t	c;
	uint64_t	d;
	uint64_t	e;
	uint64_t	f;
	uint64_t	g;
	uint64_t	h;
	u_char		*n;
	uint64_t	w[80];
	uint64_t	set;
}				t_sha5;

void			handle_input(int i, int ac, char *av[], t_ssl *ssl);
int				command(char *cmd);
void			flag_handle(char c, t_ssl *ssl, int *ac);
void			case_stdin(int ac, t_ssl *ssl);
void			case_file(int fd, t_ssl *ssl, char *file);

void			md5(char *s);

void			sha224(char *s);
void			sha256(char *s);
void			sha384(char *s);
void			sha512(char *s);

void			error_case(int code, char *input);
void			error_exit(int code, char *input);
void			reverse_bits(uint *c);

static	t_sdp	g_ssl_dp[] =
{
	{"md5", md5},
	{"sha224", sha224},
	{"sha256", sha256},
	{"sha384", sha384},
	{"sha512", sha512},
	{NULL, NULL}
};

#endif

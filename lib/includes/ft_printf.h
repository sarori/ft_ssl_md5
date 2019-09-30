/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:44:53 by sapark            #+#    #+#             */
/*   Updated: 2019/09/28 23:48:34 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>

# define SPECIFIER	"cspdiouxXf%bn"

typedef struct		s_flag_lst
{
	int				plus;
	int				minus;
	int				space;
	int				hash;
	int				zero;
	int				width;
	int				dot;
	int				precision;
	int				length_l;
	int				length_ll;
	int				length_h;
	int				length_hh;
	int				length_large;
	int				sign;
	int				per;
}					t_flag_lst;

typedef struct		s_typedt
{
	char			sp;
	void			(*f)();
}					t_typedt;

typedef struct		s_res
{
	char			*res;
	struct s_res	*next;
}					t_res;

typedef struct		s_color
{
	char			*color;
	char			*code;
}					t_color;

typedef struct		s_pf
{
	t_flag_lst		set;
	t_res			*head;
	char			*res;
	int				minus;
}					t_pf;

int					ft_printf(char *str, ...);
int					ft_dprintf(int fd, char *str, ...);
int					ft_sprintf(char *buffer, char *str, ...);
int					specifier(char *input, int *point, va_list *ap);
void				*ft_memalloc_chr(size_t size, char c);
int					setting(char *input, int *point, va_list *ap, t_pf *pf);
void				type_c(va_list *ap, t_pf *pf);
void				type_s(va_list *ap, t_pf *pf);
void				type_p(va_list *ap, t_pf *pf);
void				type_d(va_list *ap, t_pf *pf);
void				type_i(va_list *ap, t_pf *pf);
void				type_o(va_list *ap, t_pf *pf);
void				type_u(va_list *ap, t_pf *pf);
void				type_x(va_list *ap, t_pf *pf);
void				type_largex(va_list *ap, t_pf *pf);
void				type_f(va_list *ap, t_pf *pf);
void				type_per(va_list *ap, t_pf *pf);
void				type_b(va_list *ap, t_pf *pf);
int64_t				get_arg_di(va_list *ap, t_pf *pf);
u_int64_t			get_arg_uoxx(va_list *ap, t_pf *pf);
long double			get_arg_f(va_list *ap, t_pf *pf);
void				flag_setting(char *input, int *i, t_pf *pf);
void				widprec_setting(char *input, int *i, t_pf *pf);
void				length_setting(char *input, int *i, t_pf *pf);
char				*prec_handle(t_pf *pf, char *res, char *str);
char				*width_handle(t_pf *pf, char *res, char *str);
int					cal_len(t_pf *pf, u_int64_t num, int base);
char				*di_minus_handle(t_pf *pf, char *res, char *tmp);
char				*di_handle(t_pf *pf, char *res, char *tmp);
u_int64_t			cnt_flen(t_pf *pf, u_int64_t num);
char				*f_minus_handle(t_pf *pf, char *res, long double num);
u_int64_t			cvt_num(t_pf *pf, long double num);
void				flaghandle(t_pf *pf, char *res);
char				*f_handle(t_pf *pf, char *res, long double num);
char				*o_minus_handle(t_pf *pf, char *res, char *tmp);
char				*ou_handle(t_pf *pf, char *res, char *tmp);
char				*di_zerohandle(t_pf *pf, char *res, int len);
char				*f_zero_handle(t_pf *pf, char *res, int start, int size);
void				insertnode(t_pf *pf, char *res);
u_int64_t			zero_len(t_pf *pf, u_int64_t num);
char				*c_zerohandle(t_pf *pf, char *res, int len);
char				*p_handle(t_pf *pf, char *res, char *tmp, int len);
char				*di_helper(t_pf *pf, char *res, int len);
char				*di_helper2(t_pf *pf, char *res, char *tmp);
int					cal_helper(t_pf *pf, u_int64_t num, int max, int base);
char				*o_zero(t_pf *pf, int len);
char				*x_handle(t_pf *pf, char *res, char *tmp);
char				*x_helper(t_pf *pf, char *res, char *tmp);
void				type_len(va_list *ap, t_pf *pf);
char				*b_helper(t_pf *pf, char *res, char *tmp);
char				*b_handle(t_pf *pf, char *res, char *tmp);
char				*xzero(t_pf *pf, char *res, char *tmp);
char				*b_zero(t_pf *pf, char *res, char *tmp);
char				*s_null(t_pf *pf, char *res);
int					cal_slen(t_pf *pf, u_int64_t num);
void				star_setting(va_list *ap, t_pf *pf);
char				*s_null_minus(t_pf *pf, char *res);
char				*di_helper3(t_pf *pf, char *res, int len);
char				*s_handle(t_pf *pf, char *res, char *str);
void				oper_func(int idx, va_list *ap, t_pf *pf);
int					cal_slen_h(t_pf *pf, u_int64_t num, int tmp);
#endif

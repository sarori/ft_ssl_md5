/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:44:56 by sapark            #+#    #+#             */
/*   Updated: 2019/09/29 19:13:13 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>

# define BUFF_SIZE 4096

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
**---------------------memory handling---------------------
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst,
					const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

/*
**---------------------string descriptor---------------------
*/

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1,
					const char *s2, size_t n);
unsigned int		ft_strlcat(char *dest, char *src, unsigned int size);

char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack,
					const char *needle);
char				*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_putendl(char const *s);
int					ft_strchr_idx(const char *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*element_join(char *res, char *s1, char *s2);
char				*ft_scjoin(char *s1, char c, int mfree);
char				*ft_strjoinfree(char *s1, char *s2, int mfree);
char				*ft_strjoin_by(char const *s1, char const *s2, char *s3);
char				*ft_elem(char *res, char *str, int start, int size);
char				*ft_strtrimby(char const *s, char c);
char				*ft_str_toupper(char *str);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
**---------------------number descriptor---------------------
*/

void				ft_putnbr(int n);
int					ft_atoi(const char *str);
int					ft_pow(int base, int times);
void				ft_swap(int *a, int *b);
int					ft_digit(int n);

int					ft_digit_base(int n, int base);
int					ft_digit_base_u(unsigned long long n,
									unsigned long long base);
int					ft_number_length(int n);
int					ft_abs(int num);
void				ft_bubble_sort(int arr[], int count);
char				*ft_itoa(int n);
char				*ft_itoa_base(long long value, int base);
char				*ft_itoa_base_u(unsigned long long value,
									unsigned long long base);
/*
**---------------------checking---------------------
*/
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
/*
**---------------------file descriptor---------------------
*/

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
**---------------------list handling---------------------
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
**---------------------get next line---------------------
*/
int					get_next_line(const int fd, char **line);
int					get_next_line_f(int fd, char **file);

#endif

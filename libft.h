/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:02:58 by tbouder           #+#    #+#             */
/*   Updated: 2016/07/28 21:04:58 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"

# define PI		3.141592653589793
# define EQU	ft_strequ
# define CMP	ft_strcmp
# define FALSE	0
# define TRUE	1

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_block
{
	unsigned int	size;
}					t_block;

/*
** Conditions
*/

int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isnumber(int c);
int					ft_isspace(int c);
int					ft_isprime(int c);
int					ft_ishexa(int c);
int					ft_isstrstr(const char *s1, const char *s2);
int					ft_isstrnum(char *str);

/*
** Mem
*/

void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
void				*ft_memrealloc(void *ptr, size_t size);
void				ft_memdel(void **ap);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_bzero(void *s, size_t n);
void				ft_print_memory(const void *addr, size_t size);

/*
** Len
*/

size_t				ft_strlen(const char *s);
int					ft_nbrlen(int n);
int					ft_nbrlen_base(long long n, int base);
int					ft_linelen(const char *str, int i);
int					ft_hexalen(char *str);
int					ft_dbstrlen(char **str);

/*
** Strings
*/

char				*ft_strnew(size_t size);
char				*ft_strinit(char *s1);
void				ft_strdel(char **as);
void				ft_strclr(char *s);

char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnjoin(char const *s1, char const *s2, int n1,
						int n2);
char				*ft_strtrim(char const *s);
char				*ft_strtrim_char(char const *s, char c);
char				**ft_strsplit(char const *s, char c);

char				*ft_itoa(int n);
char				*ft_itoa_base(long long n, int base);
int					ft_toupper(int c);
int					ft_tolower(int c);

int					ft_strcountchar(char *str, char c);

/*
** Double strings
*/
void				ft_dbstrdel(char **str);

/*
** Numbers
*/

int					ft_atoi(const char *str);
int					ft_atoi_part(const char *str, int i);
int					ft_atoi_hexa(const char *str);
int					ft_nbrsmallest(int *nbr, int len);
int					ft_nbrlargest(int *nbr, int len);
int					ft_next_prime(int nb);
int					*ft_nbrnew(size_t size);
int					ft_nbrcmp(int nb1, int nb2);

/*
** Prints
*/

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_base(long long nb, int base, int maj);
void				ft_putnbr_fd(int n, int fd);
void				ft_nbrendl(int s);

/*
** Lists
*/

t_list				*ft_lstnew(void const *content, size_t c_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lststart(t_list **list, void *content, size_t c_size);
void				ft_lstend(t_list **list, void *content, size_t c_size);
void				ft_lstclr(t_list **begin_list);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list*elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_lstlen(t_list *begin_list);
void				ft_lstprint(t_list *begin_list);
int					ft_lstcontentsize(t_list *begin_list);
char				*ft_lsttostr(t_list **list);

/*
** Math
*/

int					ft_rand(int max);
double				ft_power(double nb, double power);
double				ft_factorial(double nb);
int					ft_fibonacci(int nb);
int					ft_sqrt(int nb);
double				ft_sin(double nb);
double				ft_cos(double nb);
double				ft_tan(double nb);
int					ft_pgcd(int nb1, int nb2);

/*
** Hash
*/
unsigned int		ft_hash_superfast(const char *data, int len);
unsigned int		ft_hash_djbtwo(char *str, int len);
unsigned int		ft_hash_sdbm(char *str, int len);
unsigned long int	adler_thirtytwo(const void *str, unsigned int len);
unsigned int		ft_hash_little(char *str, int len);

#endif

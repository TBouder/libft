# README #

[Libft](https://mega.nz/#!hpRxmLBJ!SB90oAfdoSDAZ3TWidffhGqtWfeTZI0_gyTGzE9uvPU)

# ft_is
* int		ft_isalnum(int c)
* int		ft_isalpha(int c)
* int		ft_isascii(int c)
* int		ft_isdigit(int c)
* int		ft_ishexa(int c)
* int		ft_isnumber(int c)
* int		ft_isprime(int c)
* int		ft_isprint(int c)
* int		ft_isspace(int c)

# ft_len
* int		ft_hexalen(char *str)
* int		ft_linelen(const char *str, int i)
* int		ft_nbrlen(int n)
* size_t	ft_strlen(const char *str)

# ft_lst
* void		ft_lstadd(t_list **alst, t_list *new)
* void		ft_lstclr(t_list **begin_list)
* int		ft_lstcontentsize(t_list *begin_list)
* void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
* void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
* void		ft_lstend(t_list **list, void *content, size_t c_size)
* void		ft_lstiter(t_list *lst, void (f)(t_list *elem))
* int		ft_lstlen(t_list *begin_list)
* t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
* t_list	*ft_lstnew(void const *content, size_t c_size)
* void		ft_lstprint(t_list *begin_list)
* void		ft_lststart(t_list **list, void *content, size_t c_size)
* char		*ft_lsttostr(t_list **list)

# ft_math
* double	ft_cos(double nb) 
* double	ft_sin(double nb)
* double	ft_tan(double nb)
* double	ft_factorial(double nb)
* double	ft_power(double nb, double power)
* int		ft_sqrt(int nb)
* int		ft_fibonacci(int nb)
* int		ft_rand(int nb)

# ft_mem
* void		ft_bzero(void *s, size_t n)
* void		*ft_memalloc(size_t size)
* void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
* void		*ft_memchr(const void *s, int c, size_t n)
* int		ft_memcmp(const void *s1, const void *s2, size_t n)
* void		*ft_memcpy(void *dst, const void *src, size_t n)
* void		ft_memdel(void **ap)
* void		*ft_memmove(void *dst, const void *src, size_t len)
* void		*ft_memset(void *b, int c, size_t len)
* void		*ft_realloc(void *ptr, size_t size)


# ft_nb
# ft_print
# ft_str
# GNL
# Libft  

[PDF](https://mega.nz/#!hpRxmLBJ!SB90oAfdoSDAZ3TWidffhGqtWfeTZI0_gyTGzE9uvPU)

###Gameplay  
>Le projet libft vous fait écrire une bibliothèque de fonctions utiles que vous pourrez ensuite utiliser dans la vaste majorité de vos projets de C cette année et ainsi vous faire gagner beaucoup de temps. Ce projet vous demande d’écrire beaucoup de code que vous avez déja réalisé pendant la piscine, ce qui en fait un excellent moment pour faire le point sur votre avancement.
>Dans une première partie, vous devez recoder un ensemble de fonctions de la libc telles que décrites dans leur man respectif sur votre système. Vos fonctions devront avoir exactement le même prototype et le même comportement que les originales. Leur nom devra être préfixé par “ft_”. Par exemple strlen devient ft_strlen.
>Dans une seconde partie, vous devrez coder un certain nombre de fonctions absentes de la libc ou présentes dans une forme différente. Certaines de ces fonctions peuvent avoir de l’intéret pour faciliter l’écriture des fonctions de la première partie.

#### ft_is
```c
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_ishexa(int c);
int		ft_isnumber(int c);
int		ft_isprime(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
```

#### ft_len
```c
int			ft_hexalen(char *str);
int			ft_linelen(const char *str, int i);
int			ft_nbrlen(int n);
size_t	ft_strlen(const char *str);
```

#### ft_lst
```c
void		ft_lstadd(t_list **alst, t_list *new);
void		ft_lstclr(t_list **begin_list);
int			ft_lstcontentsize(t_list *begin_list);
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void		ft_lstend(t_list **list, void *content, size_t c_size);
void		ft_lstiter(t_list *lst, void (f)(t_list *elem));
int			ft_lstlen(t_list *begin_list);
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list	*ft_lstnew(void const *content, size_t c_size);
void		ft_lstprint(t_list *begin_list);
void		ft_lststart(t_list **list, void *content, size_t c_size);
char		*ft_lsttostr(t_list **list);
```

#### ft_math
```c
double		ft_cos(double nb);
double		ft_sin(double nb);
double		ft_tan(double nb);
double		ft_factorial(double nb);
double		ft_power(double nb, double power);
int			ft_sqrt(int nb);
int			ft_fibonacci(int nb);
int			ft_rand(int nb);
```

#### ft_mem
```c
void		ft_bzero(void *s, size_t n);
void		*ft_memalloc(size_t size);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_memdel(void **ap);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_realloc(void *ptr, size_t size);
```

#### ft_nb
```c
int			ft_atoi(const char *str);
int			ft_atoi_hexa(const char *str);
int			ft_atoi_part(const char *str, int i);
int			ft_nbrlargest(int *nbr, int len);
int			ft_nbrsmallest(int *nbr, int len);
int			*ft_nbrnew(size_t size);
int			ft_next_prime(int nb);
```

#### ft_print
```c
void		ft_nbrendl(int nb);
void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl(char const *str);
void		ft_putendl_fd(char const *str, int fd);
void		ft_putnbr(int nb);
void		ft_putnbr_fd(int nb, int fd);
void		ft_putnbr_base(int nb, int base);
void		ft_putstr(char const *str);
void		ft_putstr_fd(char const *str, int fd);
```

#### ft_str
```c
char		*ft_itoa(int n);
char		*ft_itoa_base(int n, int base);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strchr(const char *s, int c);
void		ft_strclr(char *s);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
void		ft_strdel(char **as);
char		*ft_strdup(const char *s1);
int			ft_strequ(char const *s1, char const *s2);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strncat(char *s1, const char *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *dst, const char *src, size_t n);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strnew(size_t size);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
char		*ft_strrchr(const char *s, int c);
char		**ft_strsplit(char const *s, char c);
char		*ft_strstr(const char *s1, const char *s2);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s);
char		*ft_strtrim_char(char const *s, char c);
int			ft_tolower(int c);
int			ft_toupper(int c);
```

#### GNL
```c
int		get_next_line(int const fd, char **line);
```

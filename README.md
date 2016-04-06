# Libft  

[PDF](https://mega.nz/#!hpRxmLBJ!SB90oAfdoSDAZ3TWidffhGqtWfeTZI0_gyTGzE9uvPU)

###Gameplay  
>Le projet libft vous fait écrire une bibliothèque de fonctions utiles que vous pourrez ensuite utiliser dans la vaste majorité de vos projets de C cette année et ainsi vous faire gagner beaucoup de temps. Ce projet vous demande d’écrire beaucoup de code que vous avez déja réalisé pendant la piscine, ce qui en fait un excellent moment pour faire le point sur votre avancement.
>Dans une première partie, vous devez recoder un ensemble de fonctions de la libc telles que décrites dans leur man respectif sur votre système. Vos fonctions devront avoir exactement le même prototype et le même comportement que les originales. Leur nom devra être préfixé par “ft_”. Par exemple strlen devient ft_strlen.
>Dans une seconde partie, vous devrez coder un certain nombre de fonctions absentes de la libc ou présentes dans une forme différente. Certaines de ces fonctions peuvent avoir de l’intéret pour faciliter l’écriture des fonctions de la première partie.

#### ft_is
* int		ft\_isalnum(int c)
* int		ft\_isalpha(int c)
* int		ft\_isascii(int c)
* int		ft\_isdigit(int c)
* int		ft\_ishexa(int c)
* int		ft\_isnumber(int c)
* int		ft\_isprime(int c)
* int		ft\_isprint(int c)
* int		ft\_isspace(int c)

#### ft\_len
* int		ft\_hexalen(char \*str)
* int		ft\_linelen(const char \*str, int i)
* int		ft\_nbrlen(int n)
* size\_t	ft\_strlen(const char \*str)

#### ft\_lst
* void		ft\_lstadd(t\_list \*\*alst, t\_list \*new)
* void		ft\_lstclr(t\_list \*\*begin\_list)
* int		ft\_lstcontentsize(t\_list \*begin\_list)
* void		ft\_lstdel(t\_list \*\*alst, void (\*del)(void \*, size\_t))
* void		ft\_lstdelone(t\_list \*\*alst, void (\*del)(void \*, size\_t))
* void		ft\_lstend(t\_list \*\*list, void \*content, size\_t c\_size)
* void		ft\_lstiter(t\_list \*lst, void (f)(t\_list \*elem))
* int		ft\_lstlen(t\_list \*begin\_list)
* t\_list	\*ft\_lstmap(t\_list \*lst, t\_list \*(\*f)(t\_list \*elem))
* t\_list	\*ft\_lstnew(void const \*content, size\_t c\_size)
* void		ft\_lstprint(t\_list \*begin\_list)
* void		ft\_lststart(t\_list \*\*list, void \*content, size\_t c\_size)
* char		\*ft\_lsttostr(t\_list \*\*list)

#### ft\_math
* double	ft\_cos(double nb)
* double	ft\_sin(double nb)
* double	ft\_tan(double nb)
* double	ft\_factorial(double nb)
* double	ft\_power(double nb, double power)
* int		ft\_sqrt(int nb)
* int		ft\_fibonacci(int nb)
* int		ft\_rand(int nb)

#### ft\_mem
* void		ft\_bzero(void \*s, size\_t n)
* void		\*ft\_memalloc(size\_t size)
* void		\*ft\_memccpy(void \*dst, const void \*src, int c, size\_t n)
* void		\*ft\_memchr(const void \*s, int c, size\_t n)
* int		ft\_memcmp(const void \*s1, const void \*s2, size\_t n)
* void		\*ft\_memcpy(void \*dst, const void \*src, size\_t n)
* void		ft\_memdel(void \*\*ap)
* void		\*ft\_memmove(void \*dst, const void \*src, size\_t len)
* void		\*ft\_memset(void \*b, int c, size\_t len)
* void		\*ft\_realloc(void \*ptr, size\_t size)

#### ft\_nb
* int		ft\_atoi(const char \*str)
* int		ft\_atoi\_hexa(const char \*str)
* int		ft\_atoi\_part(const char \*str, int i)
* int		ft\_nbrlargest(int \*nbr, int len)
* int		ft\_nbrsmallest(int \*nbr, int len)
* int		\*ft\_nbrnew(size\_t size)
* int		ft\_next\_prime(int nb)

#### ft\_print
* void		ft\_nbrendl(int nb)
* void		ft\_putchar(char c)
* void		ft\_putchar\_fd(char c, int fd)
* void		ft\_putendl(char const \*str)
* void		ft\_putendl\_fd(char const \*str, int fd)
* void		ft\_putnbr(int nb)
* void		ft\_putnbr\_fd(int nb, int fd)
* void		ft\_putnbr\_base(int nb, int base)
* void		ft\_putstr(char const \*str)
* void		ft\_putstr\_fd(char const \*str, int fd)

#### ft\_str
* char		\*ft\_itoa(int n)
* char		\*ft\_itoa\_base(int n, int base)
* char		\*ft\_strcat(char \*s1, const char \*s2)
* char		\*ft\_strchr(const char \*s, int c)
* void		ft\_strclr(char \*s)
* int		ft\_strcmp(const char \*s1, const char \*s2)
* char		\*ft\_strcpy(char \*dst, const char \*src)
* void		ft\_strdel(char \*\*as)
* char		\*ft\_strdup(const char \*s1)
* int		ft\_strequ(char const \*s1, char const \*s2)
* void		ft\_striter(char \*s, void (\*f)(char \*))
* void		ft\_striteri(char \*s, void (\*f)(unsigned int, char \*))
* char		\*ft\_strjoin(char const \*s1, char const \*s2)
* size\_t	ft\_strlcat(char \*dst, const char \*src, size\_t size)
* char		\*ft\_strmap(char const \*s, char (\*f)(char))
* char		\*ft\_strmapi(char const \*s, char (\*f)(unsigned int, char))
* char		\*ft\_strncat(char \*s1, const char \*s2, size\_t n)
* int		ft\_strncmp(const char \*s1, const char \*s2, size\_t n)
* char		\*ft\_strncpy(char \*dst, const char \*src, size\_t n)
* int		ft\_strnequ(char const \*s1, char const \*s2, size\_t n)
* char		\*ft\_strnew(size_t size)
* char		\*ft\_strnstr(const char \*s1, const char \*s2, size\_t n)
* char		\*ft\_strrchr(const char \*s, int c)
* char		\*\*ft\_strsplit(char const \*s, char c)
* char		\*ft\_strstr(const char \*s1, const char \*s2)
* char		\*ft\_strsub(char const \*s, unsigned int start, size\_t len)
* char		\*ft\_strtrim(char const \*s)
* char		\*ft\_strtrim\_char(char const \*s, char c)
* int		ft\_tolower(int c)
* int		ft\_toupper(int c)

#### GNL
* int		get_next_line(int const fd, char \*\*line)

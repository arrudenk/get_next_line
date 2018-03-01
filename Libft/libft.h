/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:15:27 by arrudenk          #+#    #+#             */
/*   Updated: 2017/12/19 15:15:43 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIBFT_H
# define LIBFT_LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# define W_SPACE(x) (x == ' ' || x == '\t' || x == '\r' || x == '\f')

int				ft_atoi(const char *str);
char			*ft_itoa(int n);

void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int ends, size_t bts);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *in, int fnd, size_t cnt);
int				ft_memcmp(const void *arr1, const void *arr2, size_t n);

size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *str);
char			*ft_strndup(const char *str1, size_t len);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dest, const char *str, size_t num);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *str, size_t len);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strchr(const char *string, int symbol);
char			*ft_strrchr(const char *str, int ch);
char			*ft_strstr(const char *dest, const char *source);
char			*ft_strnstr(const char *dest, const char *source, size_t lth);
int				ft_strcmp(const char *str1, const char *str2);
int				ft_strncmp(const char *str1, const char *str2, size_t num);

int				ft_isalpha(int chr);
int				ft_isdigit(int dgt);
int				ft_isalnum(int chr);
int				ft_isascii(int chr);
int				ft_isprint(int chr);

int				ft_toupper(int chr);
int				ft_tolower(int chr);

void			ft_striter(char *s, void (*f)(char *));

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_lstadd(t_list **adlst, t_list *n);
void			ft_lstdel(t_list **adlst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **adlst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(const char *s);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putendl(const char *s);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);

int				ft_manywords(char const *str, char c);
int				ft_isupper(int c);
int				ft_islower(int c);
char			*ft_strndup(const char *s1, size_t n);

#endif

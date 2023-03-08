/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 09:06:10 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/03/08 15:12:14 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//get_next_line
char	*get_next_line(int fd);
char	*clear_stash(char *stash);
char	*add_to_stash(char *stash);
char	*read_and_stash(int fd, char *stash, char *read_file, char *str);

//get_next_line_utils
int		gnl_strchr(char *str);

//ft_printf
int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_put_pointer(void *nbr, char *base);
int		ft_putnbr(int nbr);
int		ft_putnbr_unsigned(unsigned int nbr);
int		ft_hexadecimal(unsigned int nbr, char *base);

//Part I
int		ft_atoi(const char *str);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t count, size_t n);
int		ft_isalnum(int alnum);
int		ft_isalpha(int letter);
int		ft_isascii(int value);
int		ft_isdigit(int digit);
int		ft_toupper(int value);
int		ft_tolower(int value);
int		ft_isprint(int value);
void	*ft_memchr(const void *str, int ch, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *str, int ch, size_t n);
char	*ft_strchr(const char *str, int n);
char	*ft_strdup(const char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strnstr(const char *str, const char *ch, size_t n);
char	*ft_strrchr(const char *str, int n);
size_t	ft_strlen(char const *str);
size_t	ft_strlcpy(char *dest, char const *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, unsigned int nb);

//Part II
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//BONUS
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *value);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:06:43 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/27 17:36:50 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <stddef.h>

size_t			ft_strlen(const char *s);
size_t			ft_lllen(long long n);
size_t			ft_lllen_base(long long n, size_t base_len);
size_t			ft_ulllen(unsigned long long n);
size_t			ft_ulllen_base(unsigned long long n, size_t base_len);

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isspace(int c);

char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strstr(const char *big, const char *little);

char			*ft_strdup(const char *s);
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *s1, const char *set);
char			**ft_split(const char *str, char c);

char			*ft_strmapi(const char *s, 
					char (*f)(unsigned int, char));
void			ft_striteri(const char *s, 
					void (*f)(unsigned int, const char *));
int				ft_strany(const char *s, int (*f)(char));
int				ft_strall(const char *s, int (*f)(char));

#endif

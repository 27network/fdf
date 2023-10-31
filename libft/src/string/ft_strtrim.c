/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:47:39 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/27 02:45:57 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/macros.h>
#include <ft/string.h>
#include <stdlib.h>

static int	ft_is_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (i++ < ft_strlen(set))
		if (set[i - 1] == c)
			return (1);
	return (0);
}

static size_t	ft_trimmed_size(const char *s1, const char *set)
{
	size_t	size;

	size = ft_strlen(s1);
	while (*s1 && ft_is_set(*s1, set))
	{
		s1++;
		size--;
	}
	if (!*s1)
		return (size);
	while (*s1)
		s1++;
	s1--;
	while (ft_is_set(*s1, set))
	{
		s1--;
		size--;
	}
	return (size);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	size;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		set = "";
	size = ft_trimmed_size(s1, set);
	if (size == 0)
	{
		str = malloc(1);
		*str = 0;
		return (str);
	}
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*s1 && ft_is_set(*s1, set))
		s1++;
	str[size] = 0;
	while (size--)
		str[size] = s1[size];
	return (str);
}

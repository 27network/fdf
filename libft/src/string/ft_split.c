/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:58:20 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/27 02:45:41 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/macros.h>
#include <ft/string.h>
#include <stdlib.h>

static int	ft_count_words(const char *str, char c)
{
	int		count;

	if (str == NULL)
		return (0);
	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

static char	*ft_splitdup(const char *str, char c)
{
	int		length;
	char	*dest;
	char	*orig_dest;

	length = 0;
	while (str[length] && str[length] != c)
		length++;
	dest = malloc(length + 1);
	orig_dest = dest;
	if (dest != NULL)
	{
		while (*str && length)
		{
			*dest = *str;
			dest++;
			str++;
			length--;
		}
		*dest++ = '\0';
	}
	return (orig_dest);
}

char	**ft_split(const char *str, char c)
{
	char	**tab;
	int		i;

	tab = malloc((ft_count_words(str, c) + 1) * sizeof(char *));
	if (tab == NULL)
		return (tab);
	tab[ft_count_words(str, c)] = NULL;
	if (str == NULL || !*str)
		return (tab);
	i = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			tab[i++] = ft_splitdup(str, c);
		while (*str && *str != c)
			str++;
	}
	return (tab);
}

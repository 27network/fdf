/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:36:08 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/25 22:51:05 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	length;
	size_t	new_length;
	char	*substr;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (start > length)
	{
		substr = malloc(1);
		*substr = 0;
		return (substr);
	}
	new_length = ft_strlen(s + start);
	if (new_length > len)
		new_length = len;
	substr = malloc((new_length + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	substr[new_length] = 0;
	while (new_length--)
		substr[new_length] = s[start + new_length];
	return (substr);
}

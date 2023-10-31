/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 00:04:16 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/25 22:50:30 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	if (s)
	{
		len = ft_strlen(s);
		if ((unsigned char)c == 0)
			return ((char *)s + len);
		while (len--)
			if (s[len] == (unsigned char)c)
				return ((char *)s + len);
	}
	return (NULL);
}

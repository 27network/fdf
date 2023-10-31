/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:13:56 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/25 22:49:43 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	size;
	char	*new;

	if (!s || !f)
		return ((char *)s);
	size = ft_strlen(s);
	new = ft_strdup(s);
	if (!new)
		return (NULL);
	while (size--)
		new[size] = f(size, new[size]);
	return (new);
}

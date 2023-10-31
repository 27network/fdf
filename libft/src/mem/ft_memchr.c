/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 23:41:36 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/25 22:52:48 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem.h>
#include <stdint.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	uint8_t	*ptr;
	size_t	i;

	if (!s || !n)
		return (NULL);
	i = 0;
	ptr = (uint8_t *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return (((void *)s) + i);
		i++;
	}
	return (NULL);
}

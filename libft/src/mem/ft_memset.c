/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:34:31 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/25 22:53:17 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem.h>
#include <stdint.h>

/**
 * @brief			Fills the first n bytes of the memory area pointed to by 
 * 					s with the constant byte c.
 *
 * @param s			The target memory area.
 * @param c			The character to fill the area with.
 * @param n			The size of the area to fill.
 *
 * @return void *	The target memory area provided in s.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	uint8_t	*ptr;

	if (s)
	{
		ptr = (uint8_t *)s;
		while (n--)
			*ptr++ = c;
	}
	return (s);
}

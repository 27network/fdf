/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:46:29 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/25 22:53:06 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem.h>
#include <stdint.h>

/**
 * @brief			Copy n bytes from the object pointed to by s2 into the object 
 * 					pointed to by s1.
 *
 * @param s1		Pointer to the first memory area (the destination).
 * @param s2		Pointer to the second memory area (the source).
 * @param n			The size to copy.
 *
 * @return void *	The target memory area provided in s1.
 */
void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	uint8_t	*ptr1;
	uint8_t	*ptr2;

	if (s1 && s2)
	{
		ptr1 = (uint8_t *)s1;
		ptr2 = (uint8_t *)s2;
		while (n--)
			*ptr1++ = *ptr2++;
	}
	return (s1);
}

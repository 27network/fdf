/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 23:20:11 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/25 22:53:12 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem.h>
#include <stdint.h>

/**
 * @brief			Copy n bytes from the object pointed to by s2 into the object 
 * 					pointed to by s1. Copying takes place as if the n bytes from 
 * 					the object pointed to by s2 are first copied into a temporary 
 * 					array of n bytes that does not overlap the objects pointed 
 * 					to by s1 and s2, and then the n bytes from the temporary array 
 *	 				are copied into the object pointed to by s1.
 *
 * @param s1		Pointer to the first memory area (the destination).
 * @param s2		Pointer to the second memory area (the source).
 * @param n			The size to copy.
 *
 * @return void *	The target memory area provided in s1.
 */
void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	uint8_t	*ptr1;
	uint8_t	*ptr2;
	size_t	i;

	if (!s1 || !s2)
		return (s1);
	ptr1 = (uint8_t *)s1;
	ptr2 = (uint8_t *)s2;
	i = 0;
	if (s1 > s2)
		while (n--)
			ptr1[n] = ptr2[n];
	else
		while (i++ < n)
			ptr1[i - 1] = ptr2[i - 1];
	return (s1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 23:46:07 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/25 22:53:00 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem.h>
#include <stdint.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	uint8_t	*ptr1;
	uint8_t	*ptr2;

	if (!s1 || !s2)
		return (0);
	if (!n--)
		return (0);
	ptr1 = (uint8_t *) s1;
	ptr2 = (uint8_t *) s2;
	while (n && *ptr1 == *ptr2)
	{
		n--;
		ptr1++;
		ptr2++;
	}
	return (*ptr1 - *ptr2);
}

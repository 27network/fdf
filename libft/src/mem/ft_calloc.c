/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:11:31 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/25 22:52:22 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem.h>
#include <stdint.h>
#include <stdlib.h>

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void		*target;
	uint64_t	size;

	if (nelem == 0 || elsize == 0)
		return (malloc(1));
	if ((int64_t)nelem < 0 || (int64_t)elsize < 0)
		return (NULL);
	size = nelem * elsize;
	if (size > SIZE_MAX)
		return (NULL);
	target = (void *)malloc((size_t)size);
	if (target)
		ft_bzero(target, size);
	return (target);
}

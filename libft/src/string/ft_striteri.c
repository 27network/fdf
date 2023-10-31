/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:27:50 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/25 22:47:27 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>

void	ft_striteri(const char *s, void (*f)(unsigned int, const char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (*s++)
		f(i++, s - 1);
}

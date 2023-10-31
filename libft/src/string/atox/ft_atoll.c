/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:17:53 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/25 22:29:15 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string/parse.h>
#include <ft/string.h>

//FIXME: long long underflow when negative number is passed
long long	ft_atoll(const char *nptr)
{
	long long	res;
	int			mult;

	res = 0;
	mult = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			mult = -mult;
	while (ft_isdigit(*nptr))
		res = res * 10 + (*nptr++ - '0');
	return (res * mult);
}

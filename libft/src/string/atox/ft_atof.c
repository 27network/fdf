/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:24:26 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/27 02:46:14 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/macros.h>
#include <ft/string/parse.h>
#include <ft/string.h>

static float	after_dot_part(const char *nptr)
{
	float	res;
	int		mult;

	res = 0;
	mult = 1;
	while (ft_isdigit(*nptr))
	{
		res = res * 10 + (*nptr++ - '0');
		mult /= 10;
	}
	return (res * mult);
}

float	ft_atof(const char *nptr)
{
	float	res;
	int		mult;

	res = 0;
	mult = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			mult = -mult;
	while (ft_isdigit(*nptr))
		res = res * 10 + (*nptr++ - '0');
	if (*nptr == '.')
		res += after_dot_part(++nptr);
	return (res * mult);
}

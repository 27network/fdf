/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:03:18 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/27 17:56:32 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>
#include <stdlib.h>

static void	ft_fill_number(
		char *str, 
		const char *base, 
		size_t len, 
		unsigned long long nbr
) {
	if (nbr >= (unsigned long long)ft_strlen(base))
		ft_fill_number(str, base, len - 1, nbr / ft_strlen(base));
	str[len - 1] = base[nbr % ft_strlen(base)];
}

char	*ft_ulltoa_base(unsigned long long n, const char *base)
{
	unsigned long long	nbr;
	size_t				nb_len;
	char				*str;

	nbr = n;
	nb_len = ft_ulllen_base(nbr, ft_strlen(base));
	str = malloc((nb_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[nb_len] = 0;
	ft_fill_number(str, base, nb_len, nbr);
	return (str);
}

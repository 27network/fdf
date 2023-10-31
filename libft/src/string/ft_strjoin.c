/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:42:56 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/25 22:48:14 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	new_length;
	char	*new_string;
	size_t	i;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	new_length = ft_strlen(s1) + ft_strlen(s2);
	new_string = malloc((new_length + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	i = 0;
	while (i++ < ft_strlen(s1))
		new_string[i - 1] = s1[i - 1];
	i = 0;
	while (i++ < ft_strlen(s2))
		new_string[ft_strlen(s1) + i - 1] = s2[i - 1];
	new_string[new_length] = 0;
	return (new_string);
}

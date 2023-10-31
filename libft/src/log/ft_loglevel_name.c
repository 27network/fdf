/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loglevel_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 23:24:21 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/25 23:52:01 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/log.h>

const char	*ft_loglevel_name(t_loglevel type)
{
	if (type == INFO)
		return (GRAY "(" BLUE "i" GRAY ")" RESET B_WHITE);
	else if (type == WARN)
		return (GRAY "(" YELLOW "!" GRAY ")" RESET B_WHITE);
	else if (type == ERROR)
		return (GRAY "(" RED "x" GRAY ")" RESET B_WHITE);
	else if (type == DEBUG)
		return (GRAY "(" MAGENTA "#" GRAY ")" RESET B_WHITE);
	else if (type == FATAL)
		return (GRAY "(" RED "X" GRAY ")" RESET B_WHITE);
	return (GRAY "(" DARK_GRAY "?" GRAY ")" RESET B_WHITE);
}

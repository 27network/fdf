/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 23:33:47 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/26 00:41:50 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io.h>
#include <ft/log.h>
#include <ft/string.h>

void	ft_log_fd(
		int fd, 
		t_loglevel level, 
		const char *process, 
		const char *msg
) {
	const char	*level_str;

	if (level == NONE || level < FT_LOG_LEVEL)
		return ;
	level_str = ft_loglevel_name(level);
	ft_putstr_fd(fd, level_str);
	ft_putstr_fd(fd, RESET " ");
	ft_putstr_fd(fd, process);
	ft_putstr_fd(fd, RESET GRAY ": " RESET);
	ft_putendl_fd(fd, msg);
}

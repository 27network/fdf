/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 23:20:52 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/26 00:33:05 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# include <ft/colors.h>

# ifndef FT_LOG_LEVEL
#  define FT_LOG_LEVEL FATAL 
# endif

typedef enum e_loglevel
{
	TRACE = 0,
	DEBUG,
	INFO,
	WARN,
	ERROR,
	FATAL,
	NONE
}	t_loglevel;

void		ft_log(t_loglevel level, const char *process, const char *msg);
void		ft_log_fd(int fd, t_loglevel level, const char *process,
				const char *msg);
const char	*ft_loglevel_name(t_loglevel level);

#endif

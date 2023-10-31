/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 23:25:20 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/26 00:44:25 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/log.h>
#include <unistd.h>

void	ft_log(t_loglevel type, const char *process, const char *msg)
{
	ft_log_fd(STDOUT_FILENO, type, process, msg);
}

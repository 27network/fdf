/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtrm <oss@xtrm.me>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:49:57 by xtrm              #+#    #+#             */
/*   Updated: 2023/10/25 23:56:23 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

void			ft_putchar(char c);
void			ft_putchar_fd(int fd, char c);

void			ft_putstr(const char *s);
void			ft_putstr_fd(int fd, const char *s);

void			ft_putendl(const char *s);
void			ft_putendl_fd(int fd, const char *s);

void			ft_putnbr(int n);
void			ft_putnbr_fd(int fd, int n);

#endif

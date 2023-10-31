/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 23:29:28 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/25 23:50:40 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

/* Control characters */
# define RESET			"\033[0m"
# define BOLD			"\033[1m"
# define DIM			"\033[2m"
# define ITALIC			"\033[3m"
# define UNDERLINE		"\033[4m"
# define BLINK			"\033[5m"
# define REVERSE		"\033[7m"
# define HIDDEN			"\033[8m"

/* Foreground colors */
# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define DARK_GRAY		"\033[90m"
# define GRAY			"\033[37m"
# define WHITE			"\033[38m"

/* Background colors */
# define BG_BLACK		"\033[40m"
# define BG_RED			"\033[41m"
# define BG_GREEN		"\033[42m"
# define BG_YELLOW		"\033[43m"
# define BG_BLUE		"\033[44m"
# define BG_MAGENTA		"\033[45m"
# define BG_CYAN		"\033[46m"
# define BG_DARK_GRAY	"\033[100m"
# define BG_GRAY		"\033[47m"
# define BG_WHITE		"\033[107m"

/* Bold foreground colors */
# define B_BLACK		"\033[1;30m"
# define B_RED			"\033[1;31m"
# define B_GREEN		"\033[1;32m"
# define B_YELLOW		"\033[1;33m"
# define B_BLUE			"\033[1;34m"
# define B_MAGENTA		"\033[1;35m"
# define B_CYAN			"\033[1;36m"
# define B_WHITE		"\033[1;37m"

#endif

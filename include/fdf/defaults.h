/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defaults.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:59:01 by kiroussa          #+#    #+#             */
/*   Updated: 2024/01/03 18:20:32 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFAULTS_H
# define DEFAULTS_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

# ifndef PROGRAM_TITLE
#  define PROGRAM_TITLE "fdf"
# endif // PROGRAM_TITLE

# ifndef FILE_EXTENSION
#  define FILE_EXTENSION ".fdf"
# endif // FILE_EXTENSION

# ifndef FDF_WINDOW_WIDTH
#  define FDF_WINDOW_WIDTH 1920
# endif // FDF_WINDOW_WIDTH

# ifndef FDF_WINDOW_HEIGHT
#  define FDF_WINDOW_HEIGHT 1080
# endif // FDF_WINDOW_HEIGHT

#endif // DEFAULTS_H

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:56:41 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/25 23:18:06 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/list.h>

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list	*prev;

	if (!new)
		return ;
	prev = *alst;
	*alst = new;
	while (new->next)
		new = new->next;
	new->next = prev;
}

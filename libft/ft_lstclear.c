/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:12:38 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/01 22:14:10 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	**temp;

	if ((*lst) != 0 && del)
	{
		while ((*lst) != 0)
		{
			temp = lst;
			(*del)((*lst)->content);
			free(*lst);
			*lst = (*temp)->next;
		}
	}
	else
		return ;
}

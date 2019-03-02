/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 19:59:42 by tdelabro          #+#    #+#             */
/*   Updated: 2019/03/02 20:46:07 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*head;
	t_list	*next;

	if (alst && del)
	{
		head = *alst;
		while (head)
		{
			next = head->next;
			del(head->content, head->content_size);
			free(head);
			head = next;
		}
		*alst = NULL;
	}
}

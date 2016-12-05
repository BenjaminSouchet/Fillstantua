/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:15:55 by gmonein           #+#    #+#             */
/*   Updated: 2016/12/01 19:41:15 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				ft_make_past(t_list *lst)
{
	t_list		*tmp;
	t_list		*begin;
	char		id;

	id = 'A';
	begin = lst;
	tmp = lst;
	lst->begin = NULL;
	lst = lst->next;
	while (tmp->next != NULL)
	{
		tmp->id = id;
		id++;
		tmp->placed = 0;
		tmp->begin = begin;
		lst->past = tmp;
		lst = lst->next;
		tmp = tmp->next;
	}
}

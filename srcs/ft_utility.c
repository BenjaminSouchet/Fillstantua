/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <gmonein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:40:03 by gmonein           #+#    #+#             */
/*   Updated: 2016/12/02 04:07:43 by jpeg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_list_init(t_list *lst)
{
	while (lst->next != NULL)
	{
		lst->x = -1;
		lst->y = 0;
		lst->last_pos = 0;
		lst = lst->next;
	}
}

unsigned int	*ft_del_tetris(unsigned int *tab, t_list *lst)
{
	tab[lst->y + 0] ^= (lst->itetri[0] >> (lst->x));
	tab[lst->y + 1] ^= (lst->itetri[1] >> (lst->x));
	tab[lst->y + 2] ^= (lst->itetri[2] >> (lst->x));
	tab[lst->y + 3] ^= (lst->itetri[3] >> (lst->x));
	lst->placed = 0;
	lst->last_pos = 0;
	return (tab);
}

unsigned int	*ft_erase_map(unsigned int *tab)
{
	int		i;

	i = 31;
	while (i--)
		tab[i] = 0;
	return (tab);
}

int				ft_map_min(t_list *lst)
{
	int		i;
	int		sqtr;
	int		min;

	min = 0;
	i = 0;
	sqtr = 1;
	if (lst->data.len > min)
		min = lst->data.len;
	if (lst->data.height > min)
		min = lst->data.height;
	while (lst->next != NULL)
	{
		i = i + 4;
		lst = lst->next;
	}
	while ((sqtr * sqtr) < i)
		sqtr++;
	if (min > sqtr)
		return (min);
	return (sqtr);
}

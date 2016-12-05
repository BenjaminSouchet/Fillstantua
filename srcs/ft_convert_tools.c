/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:17:06 by gmonein           #+#    #+#             */
/*   Updated: 2016/12/01 19:41:12 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned int		*ft_short_to_ul(unsigned short tetris)
{
	int				i;
	int				j;
	unsigned int	*tab;

	i = 0;
	j = 0;
	tab = (unsigned int *)malloc(sizeof(unsigned int) * 5);
	while (i < 4)
		tab[i++] = 0;
	tab[0] = ((tetris & 0xF000) << 16);
	tab[1] = ((tetris & 0x0F00) << 20);
	tab[2] = ((tetris & 0x00F0) << 24);
	tab[3] = ((tetris & 0x000F) << 28);
	tab[4] = 0;
	return (tab);
}

void				ft_make_ul(t_list *lst)
{
	while (lst->next != NULL)
	{
		lst->itetri = (unsigned int *)malloc(sizeof(unsigned int) * 5);
		lst->itetri = ft_short_to_ul(lst->tetri);
		lst = lst->next;
	}
}

unsigned int		*ft_setmap(void)
{
	unsigned int	*tab;
	int				i;

	tab = (unsigned int *)malloc(sizeof(unsigned int) * 33);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < 33)
		tab[i++] = 0;
	return (tab);
}

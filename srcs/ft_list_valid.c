/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeguet <jpeguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:54:22 by jpeguet           #+#    #+#             */
/*   Updated: 2016/12/03 01:43:54 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned short		*tab_tetri_valid(void)
{
	unsigned short		*tetri_valid;

	tetri_valid = (unsigned short *)malloc(sizeof(unsigned short) * 19);
	tetri_valid[19] = '\0';
	tetri_valid[0] = 0xF000;
	tetri_valid[1] = 0x8888;
	tetri_valid[2] = 0xCC00;
	tetri_valid[3] = 0x4E00;
	tetri_valid[4] = 0xE400;
	tetri_valid[5] = 0x8C80;
	tetri_valid[6] = 0x4C40;
	tetri_valid[7] = 0x6C00;
	tetri_valid[8] = 0x8C40;
	tetri_valid[9] = 0xC880;
	tetri_valid[10] = 0xC600;
	tetri_valid[11] = 0xE200;
	tetri_valid[12] = 0x4C80;
	tetri_valid[13] = 0x88C0;
	tetri_valid[14] = 0x2E00;
	tetri_valid[15] = 0xC440;
	tetri_valid[16] = 0xE800;
	tetri_valid[17] = 0x44C0;
	tetri_valid[18] = 0x8E00;
	return (tetri_valid);
}

static t_list_valid			*ft_list_valid(int i)
{
	t_list_valid	*vlist;
	t_list_valid	*tmp;
	unsigned short	*tetri;

	tetri = tab_tetri_valid();
	vlist = (t_list_valid *)malloc(sizeof(t_list_valid));
	tmp = vlist;
	while (tetri[i] != '\0')
	{
		tmp->tetri = tetri[i];
		tmp->next = (t_list_valid *)malloc(sizeof(t_list_valid));
		tmp = tmp->next;
		tmp->next = NULL;
		i++;
	}
	free(tetri);
	return (vlist);
}

int							ft_check_list(t_list *lst)
{
	t_list_valid	*lva;
	t_list_valid	*b_lva;
	short			valid;

	lva = ft_list_valid(0);
	b_lva = lva;
	while (lst->next != NULL)
	{
		while (lva->next != NULL && valid != 1)
		{
			if ((lst->tetri | lva->tetri) == lva->tetri && (valid = 1) == 1)
				ft_set_data_two(lst);
			lva = lva->next;
		}
		lva = b_lva;
		if (valid == 0)
			return (ft_error(1));
		valid = 0;
		lst = lst->next;
	}
	return (1);
}

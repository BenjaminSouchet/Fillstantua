/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 04:39:18 by gmonein           #+#    #+#             */
/*   Updated: 2016/11/27 07:50:44 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_set_data_one(t_list *list)
{
	if (list->tetri == 0xC880)
		list->data = ft_xy_j();
	if (list->tetri == 0x8C40)
		list->data = ft_xy_i();
	if (list->tetri == 0x6C00)
		list->data = ft_xy_h();
	if (list->tetri == 0x4C40)
		list->data = ft_xy_g();
	if (list->tetri == 0x8C80)
		list->data = ft_xy_f();
	if (list->tetri == 0xE400)
		list->data = ft_xy_e();
	if (list->tetri == 0x4E00)
		list->data = ft_xy_d();
	if (list->tetri == 0xCC00)
		list->data = ft_xy_c();
	if (list->tetri == 0x8888)
		list->data = ft_xy_b();
	if (list->tetri == 0xF000)
		list->data = ft_xy_a();
}

void		ft_set_data_two(t_list *list)
{
	if (list->tetri == 0x8E00)
		list->data = ft_xy_s();
	if (list->tetri == 0x44C0)
		list->data = ft_xy_r();
	if (list->tetri == 0xE800)
		list->data = ft_xy_q();
	if (list->tetri == 0xC440)
		list->data = ft_xy_p();
	if (list->tetri == 0x2E00)
		list->data = ft_xy_o();
	if (list->tetri == 0x88C0)
		list->data = ft_xy_n();
	if (list->tetri == 0x4C80)
		list->data = ft_xy_m();
	if (list->tetri == 0xE200)
		list->data = ft_xy_l();
	if (list->tetri == 0xC600)
		list->data = ft_xy_k();
	ft_set_data_one(list);
}

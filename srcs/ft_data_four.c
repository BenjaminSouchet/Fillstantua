/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 01:55:51 by gmonein           #+#    #+#             */
/*   Updated: 2016/12/03 01:55:55 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_data		ft_xy_k(void)
{
	t_data	data;

	data.y1 = 0;
	data.y2 = 0;
	data.y3 = 1;
	data.y4 = 1;
	data.x1 = 0;
	data.x2 = 1;
	data.x3 = 1;
	data.x4 = 2;
	data.len = 3;
	data.height = 2;
	return (data);
}

t_data		ft_xy_l(void)
{
	t_data	data;

	data.y1 = 0;
	data.y2 = 0;
	data.y3 = 0;
	data.y4 = 1;
	data.x1 = 0;
	data.x2 = 1;
	data.x3 = 2;
	data.x4 = 2;
	data.len = 3;
	data.height = 2;
	return (data);
}

t_data		ft_xy_m(void)
{
	t_data	data;

	data.y1 = 0;
	data.y2 = 1;
	data.y3 = 1;
	data.y4 = 2;
	data.x1 = 1;
	data.x2 = 0;
	data.x3 = 1;
	data.x4 = 0;
	data.len = 2;
	data.height = 3;
	return (data);
}

t_data		ft_xy_n(void)
{
	t_data	data;

	data.y1 = 0;
	data.y2 = 1;
	data.y3 = 2;
	data.y4 = 2;
	data.x1 = 0;
	data.x2 = 0;
	data.x3 = 0;
	data.x4 = 1;
	data.len = 2;
	data.height = 3;
	return (data);
}

t_data		ft_xy_o(void)
{
	t_data	data;

	data.y1 = 0;
	data.y2 = 1;
	data.y3 = 1;
	data.y4 = 1;
	data.x1 = 2;
	data.x2 = 0;
	data.x3 = 1;
	data.x4 = 2;
	data.len = 3;
	data.height = 2;
	return (data);
}

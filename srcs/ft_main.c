/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:42:47 by gmonein           #+#    #+#             */
/*   Updated: 2016/12/07 04:13:41 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int argc, char **argv)
{
	t_list			*lst;
	unsigned int	*tab;
	int				size;
	t_ligne			*sct;

	if (argc != 2)
		return (0);
	sct = (t_ligne *)malloc(sizeof(t_ligne));
	tab = ft_setmap();
	(lst = ft_new_fill(argv[1]));
	if (!(ft_check_list(lst)))
		return (0);
	ft_set_data_two(lst);
	ft_make_ul(lst);
	ft_make_past(lst);
	ft_list_init(lst);
	t_sastantua(12, sct);
	size = solver(tab, lst->begin, 12, *sct);
	t_sastantua(size, sct);
	ft_print_map(lst->begin, size, *sct);
	free(sct);
	return (0);
}

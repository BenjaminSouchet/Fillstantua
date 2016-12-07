/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:42:47 by gmonein           #+#    #+#             */
/*   Updated: 2016/12/07 05:48:28 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		chack_sas(char *s)
{
	if (s[0] != 's' || s[1] != 'a' || s[2] != 's' || s[3] != '\0')
		return (0);
	return (1);
}

int				main(int argc, char **argv)
{
	t_list			*lst;
	unsigned int	*tab;
	int				size;
	t_ligne			*sct;
	int				min_height;

	if (!(argc == 2 || (argc == 3 && chack_sas(argv[2]))))
		return (0);
	tab = ft_setmap();
	lst = ft_new_fill(argv[1]);
	if (!(ft_check_list(lst)))
		return (0);
	ft_set_data_two(lst);
	ft_make_ul(lst);
	ft_make_past(lst);
	ft_list_init(lst);
	if (argc == 3 && chack_sas(argv[2]))
	{
		sct = (t_ligne *)malloc(sizeof(t_ligne));
		min_height = 1;
		t_sastantua(min_height, sct);
		size = solver_sas(tab, lst->begin, min_height, *sct);
		t_sastantua(size, sct);
		ft_print_map_sas(lst->begin, size, *sct);
		free(sct);
	}
	else
	{
			size = solver(tab, lst->begin, ft_map_min(lst->begin));
		ft_print_map(lst->begin, size);
	}
	return (0);
}

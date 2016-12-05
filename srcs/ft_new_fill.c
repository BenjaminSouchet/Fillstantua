/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 08:12:15 by gmonein           #+#    #+#             */
/*   Updated: 2016/12/03 01:38:47 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					ft_error(int error_nb)
{
	if (error_nb > 0)
	{
		write(1, INVALID_MAP, ft_strlen(INVALID_MAP));
		exit(EXIT_FAILURE);
	}
	return (-1);
}

static int			ft_valid(char *s)
{
	int i;
	int diez;
	int point;
	int	bsn;

	i = -1;
	bsn = 0;
	point = 0;
	diez = 0;
	while ((s[++i] != '\n' || s[i + 1] != '\n') && s[i])
	{
		point = (s[i] == '.') ? point + 1 : point;
		diez = (s[i] == '#') ? diez + 1 : diez;
		bsn = (s[i] == '\n') ? bsn + 1 : bsn;
	}
	if (bsn != 4 || point != 12 || diez != 4)
		return (ft_error(1));
	return (0);
}

unsigned short		ft_bits(char *s)
{
	int				i;
	int				j;
	unsigned short	res;

	i = 0;
	j = 0;
	res = 0;
	ft_valid(s);
	while (s[i])
	{
		if (s[i] == '#' || s[i] == '.')
			res = res << 1;
		if (s[i++] == '#')
			res = res + 1;
		if ((s[i] != '\n' && (i + 1) % 5 == 0))
			return (ft_error(1));
		i = ((i + 1) % 5 == 0) ? i + 1 : i;
	}
	while ((res & 0x8888) == 0)
		res = res << 1;
	while ((res & 0xF000) == 0)
		res = res << 4;
	return (res);
}

t_list				*ft_new_fill(char *file)
{
	int				fd;
	char			buf[21];
	int				readed;
	t_list			*lst;
	t_list			*tmp;

	fd = open(file, O_RDONLY);
	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	tmp = lst;
	readed = 42;
	while (readed == 42 || readed == 1)
	{
		readed = read(fd, buf, 20);
		buf[readed] = '\0';
		if ((lst->tetri = ft_bits(buf)) == 65535)
			return (NULL);
		lst->next = (t_list *)malloc(sizeof(t_list));
		lst = lst->next;
		lst->next = NULL;
		readed = read(fd, buf, 1);
		buf[1] = '\0';
	}
	close(fd);
	return ((!(readed == 0) && ft_error(1)) ? NULL : tmp);
}

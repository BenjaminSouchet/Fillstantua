/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 22:27:13 by gmonein           #+#    #+#             */
/*   Updated: 2016/12/03 01:41:57 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*fresh;

	fresh = (unsigned char *)ptr;
	while (num)
	{
		*fresh = (unsigned char)value;
		num--;
		if (num)
			fresh++;
	}
	return (ptr);
}

void			ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

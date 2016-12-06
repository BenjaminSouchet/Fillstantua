#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		*calc_nb_floors(int num, int min, int rest, int *nb_floors)
{
	int		i;
	int		*tab;

	i = 3;
	*nb_floors = 1;
	if (!(tab = (int *)malloc(sizeof(int) * 25)))
		return (NULL);
	while (i < num)
		i += (3 + (*nb_floors)++);
	min = ((num > 5 || num == 3) && num != 8 && num != 9) ? 3 : 2;
	rest = num - (min * *nb_floors);
	i = 0;
	tab[0] = min;
	while (++i < *nb_floors)
	{
		if (rest >= (*nb_floors - i) && ++min)
			rest -= (*nb_floors - i);
		tab[i] = tab [i - 1] + min;
	}
	tab[i] = 0;
	return (tab);
}

int		calc_size_door(int *tab)
{
	int		nb_floors;
	int		last_floor;
	int		size_door;

	nb_floors = 0;
	while (tab[nb_floors])
			nb_floors++;
	last_floor = tab[nb_floors - 1] - tab[nb_floors - 2];
	size_door = ((last_floor - 2) % 2) ? last_floor - 2 : last_floor - 3;
	return (size_door);
}

void	print_line(int *tab, int nb_pts, int size_door, int line, int lines)
{
	int		pos;
	int		start;
	int		end;
	char	c;

	pos = -1;
	if (line >= (lines - size_door))
	{
		start = ((nb_pts - 1) / 2) - ((size_door - 1) / 2);
		end = start + size_door;
		while (++pos < nb_pts)
		{
			c = (pos >= start && pos < end) ? '|' : '*';
			if (size_door > 3 && pos == (end - 2) &&
				line == (lines - (((size_door - 1) / 2) + 1)))
				c = '$';
			write(1, &c, 1);
		}
	}
	else
		while (nb_pts--)
			write(1, "*", 1);
	write(1, "\\\n", 2);
}

void	print_fillstantua(int *tab, int wlen, int num, int line)
{
	int		part_two;
	int		nb_pts;
	int		c_floor;
	int		size_door;
	int		pos;

	c_floor = 0;
	part_two = 0;
	size_door = calc_size_door(tab);
	while (++line < num && (pos = -1) != 0)
	{
		if (line == tab[c_floor] && ++c_floor)
			part_two += ((((c_floor + 1) / 2) * 2) + 2);
		nb_pts = (line * 2 + 1) + part_two;
		while (++pos < ((wlen - nb_pts) / 2))
			write(1, " ", 1);
		write(1, "/", 1);
		print_line(tab, nb_pts, size_door, line, num);
	}
}

int		main(int ac, char **av)
{
	int		*tab;
	int		nb_floors;
	int		wlen;
	int		num;

	if (ac == 2)
		num = atoi(av[1]);
	if (ac != 2 || num < 1 || num > 25)
		return (0);
	ac = 0;
	wlen = 0;
	tab = calc_nb_floors(num, 0, 0, &nb_floors);
	while (++ac < nb_floors)
		wlen += ((((ac + 1) / 2) * 2) + 2);
	wlen += ((num - 1) * 2 + 1);
	print_fillstantua(tab, wlen, num, -1);
	free(tab);
	return (0);
}

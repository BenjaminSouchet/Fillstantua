#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		*get_nb_floors(int num, int min, int rest)
{
	int		i;
	int		*tab;
	int		floors;

	i = 3;
	floors = 1;
	if (!(tab = (int *)malloc(sizeof(int) * 25)))
		return (NULL);
	while (i < num)
		i += (3 + floors++);
	min = ((num > 5 || num == 3) && num != 8 && num != 9) ? 3 : 2;
	rest = num - (min * floors);
	i = 0;
	tab[0] = min;
	while (++i < floors)
	{
		if (rest >= (floors - i) && ++min)
			rest -= (floors - i);
		tab[i] = tab [i - 1] + min;
	}
	tab[i] = 0;
	return (tab);
}

int		get_size_max(int *tab, int num, int c_floor, int i)
{
	int		p_two;

	p_two = 0;
	while (i < num)
	{
		if (i == *tab && ++tab && ++c_floor)
			p_two += (((c_floor + 1) / 2) * 2);
		i++;
	}
	return ((i * 2 + 1) + p_two);
}

void	print_fillstantua(int *tab, int num, int wlen, int i)
{
	int		part_two;
	int		num_pts;
	int		c_floor;
	int		tmp;

	c_floor = 0;
	part_two = 0;
	while (i < num)
	{
		if (i == *tab && ++tab && ++c_floor)
			part_two += (((c_floor + 1) / 2) * 2);
		num_pts = (i * 2 + 1) + part_two;
		tmp = -1;
		while (++tmp < ((wlen - num_pts) / 2))
			write(1, " ", 1);
		write(1, "/", 1);
		while (num_pts--)
			write(1, "*", 1);
		write(1, "\\\n", 2);
		i++;
	}
}

int		main(int ac, char **av)
{
	int		*tab;
	int		wlen;
	int		num;

	if (ac == 2)
		num = atoi(av[1]);
	if (ac != 2 || num < 1 || num > 25)
		return (0);
	tab = get_nb_floors(num, 0, 0);
	wlen = get_size_max(tab, num, 0, 0);
	print_fillstantua(tab, num, wlen, 0);
	free(tab);
	return (0);
}

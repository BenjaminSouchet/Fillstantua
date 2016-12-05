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
	{
		i += (3 + floors);
			floors++;
	}
	min = (num > 5 && num != 8 && num != 9) ? 3 : 2;
	rest = num - (min * floors);
	i = 1;
	tab[0] = min;
	while (i < floors)
	{
		if (rest >= (floors - i) && ++min)
			rest -= (floors - i);
		tab[i++] = min;
	}
	tab[i] = 0;
	return (tab);
}

int		len_last(int *tab, int num)
{
	int		i;
	int		j;
	int		tmp;
	int		c_floor;
	int		t_floor;
	int		part_two;

	i = 0;
	t_floor = -1;
	part_two = 0;
	while (i < num)
	{
		j = 0;
		tmp = 0;
		c_floor = 0;
		while (tab[j] && (tmp += tab[j++]) <= i)
			c_floor++;
		if (c_floor > t_floor)
		{
			part_two += (((c_floor + 1) / 2) * 2);
			t_floor = c_floor;
		}
		i++;
	}
	return ((i * 2 + 1) + part_two);
}

unsigned long			*print_fillstantua(int *tab, int num, int last_len)
{
	int		i;
	int		j;
	int		tmp;
	int		c_floor;
	int		t_floor;
	int		part_two;
	unsigned long		*result;

	i = 0;
	t_floor = -1;
	part_two = 0;
	tmp = 0;
	result = (unsigned long *)malloc(sizeof(unsigned long) * 65);
	while (tmp < 64)
		result[tmp++] = 0;
	while (i < num)
	{
		j = 0;
		tmp = 0;
		c_floor = 0;
		while (tab[j] && (tmp += tab[j++]) <= i)
			c_floor++;
		if (c_floor > t_floor)
		{
			part_two += (((c_floor + 1) / 2) * 2);
			t_floor = c_floor;
		}
		int part_one = (i * 2 + 1);
		int num_pts = part_one + part_two;
		/* Fin des calculs, debut du print */
		tmp = -1;
		while (++tmp < num_pts)
		{
			result[i] += 1;
			result[i] <<= 1;
		}
		result[i] <<= ((last_len - num_pts) / 2) - 1;
		/* Fin print */
		i++;
	}
	return (result);
}

#include <unistd.h>
void	print_bits(unsigned long *tab, int h)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < h)
	{
		while (tab[i] != 0)
		{
			if ((tab[i] & 1) == 1)
				write(1, "1", 1);
			else
				write(1, "0", 1);
			tab[i] >>= 1;
			j++;
		}
		j = 0;
		write(1, "\n", 1);
		i++;
	}
}

int		main(int ac, char **av)
{
	int		*tab;
	int		num;
	int		l_len;
	unsigned long		*result;

	if (ac == 2)
		num = atoi(av[1]);
	if (ac != 2 || num < 0 || num > 25)
		return (0);
	tab = get_nb_floors(num, 0, 0);
	l_len = len_last(tab, num);
	result = print_fillstantua(tab, num, l_len);
	print_bits(result, num);
	free(tab);
	free(result);
	return (0);
}

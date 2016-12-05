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

void	print_fillstantua(int *tab, int num)
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
		int part_one = (i * 2 + 1);
		int num_pts = part_one + part_two;
		/* Fin des calculs, debut du print */
		printf("/");
		tmp = -1;
		while (++tmp < num_pts)
			printf("*");
		printf("\\\n");
		/* Fin print */
		i++;
	}
}

int		main(int ac, char **av)
{
	int		*tab;
	int		num;

	if (ac == 2)
		num = atoi(av[1]);
	if (ac != 2 || num < 0 || num > 25)
		return (0);
	tab = get_nb_floors(num, 0, 0);
	print_fillstantua(tab, num);
	free(tab);
	return (0);
}

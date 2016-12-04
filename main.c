#include <stdio.h>
#include <stdlib.h>

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

int		main(void)
{
	int		i;
	int		j;
	int		*tab;

	i = 3;
	/*Affichage de verification (de 4 a 24)*/
	while (++i <= 25)
	{
		j = 0;
		printf("i : %i ---", i);
		tab = get_nb_floors(i, 0, 0);
		while (tab[j] != 0)
			printf(" %i", tab[j++]);
		printf("\n\n");
		free(tab);
	}
	return (0);
}

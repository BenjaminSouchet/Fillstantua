#include <stdio.h>
 
int     main(void)
{
    int     tab[25];
    int     etages;
    int     tmp;
    int     num;
	int		min;
 
	// initialisation du tableau
    tmp = 0;
    num = 25;
    while (tmp < 25)
        tab[tmp++] = 0;

	// compteur d'etages
    tmp = 3;
    etages = 1;
    while (tmp < num)
    {
        tmp += (3 + etages);
        etages++;
    }

	min = (num > 9) ? 3 : 2;

	// initialisation du tableau
	tmp = 0;
	while (tmp < etages)
		tab[tmp++] = min;

	// recuperation du reste
	int reste;

	reste = num - (min * etages);

	// repartition du reste
	int i = 1;
	int val = min;
	while (tab[i])
	{
		if (reste >= (etages - i) && ++val)
			reste -= (etages - i);
		tab[i++] = val; 
	}
	i = 0;
	while (tab[i])
		printf("%i\n", tab[i++]);
    return (0);
}

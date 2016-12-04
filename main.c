#include <stdio.h>
 
int     main(void)
{
    int     tab[25];
    int     etage;
    int     tmp;
    int     num;
 
	// initialisation du tableau
    tmp = 0;
    num = 2;
    while (tmp < 25)
        tab[tmp++] = 0;

	// compteur d'etage
    tmp = num;
    tmp = 3;
    etage = 1;
    while (tmp < num)
    {
        tmp += (3 + etage);
        etage++;
    }

	// initialisation du tableau
	tmp = 0;
	while (tmp < etage)
		if (num > 8)
			tab[tmp++] = 3;
		else
			tab[tmp++] = 2;

	// recuperation du reste
	int reste;

	tmp = 0;
	if (num > 8)
		reste = num - (3 * etage);
	else
		reste = num - (2 * etage);

	// repartition du reste
//	int i = (etage - 1);
//
//	while (reste != 0)
//	{
//		while (tab[i] + 1 != tab[i - 1])
//			i++;
//
//	}
    return (0);
}



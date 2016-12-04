#include <stdio.h>
#include <unistd.h>

long int		ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		result;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] >= 0 && str[i] <= 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}

int     main(int argc, char **argv)
{
    int     tab[25];
    int     etage;
    int     tmp;
    int     num;

    tmp = 0;
    num = ft_atoi(argv[1]);
	int reste;
	int i;
//	write (1, "cpt\n", 4);
		// compteur d'etage
		tmp = 3;
		etage = 1;
		while (tmp < num)
		{
			tmp += (3 + etage);
			etage++;
		}

		// initialisation du tableau
//	write (1, "ini\n", 4);
		tmp = 0;
		while (tmp < 24)
			tab[tmp++] = 0;

		// initialisation du tableau
//	write (1, "inj\n", 4);
		tmp = 0;
		while (tmp < etage)
			if (num > 8)
				tab[tmp++] = 3;
			else
				tab[tmp++] = 2;
		tmp = 0;

		// recuperation du reste
//	write (1, "rst\n", 4);
		if (num > 8)
			reste = num - (3 * etage);
		else
			reste = num - (2 * etage);

		// repartition du reste
//	write (1, "rep\n", 4);
		i = 0;
		while (reste != 0)
		{
			i = etage - 1;
			while ((tab[i - 1] != tab[i]) && tab[i])
				i--;
			if (tab[i] != 0)
			{
				tab[i] += 1;
				reste--;
			}
		}

		i = 0;
	write (1, "rep\n", 4);
		printf("%d ->", num);
	write (1, "rep\n", 4);
		while (tab[i] != 0)
		{
			printf(" %d", tab[i]);
			i++;
		}
    return (0);
}



#include <stdio.h>
 
int     main(void)
{
    int     tab[25];
    int     etage;
    int     tmp;
    int     num;
 
    tmp = 0;
    num = 2;
    while (tmp < 25)
        tab[tmp++] = 0;
    tmp = num;
    while (num < 25)
    {
        tmp = 3;
        etage = 1;
        while (tmp < num)
        {
            tmp += (3 + etage);
            etage++;
        }
        printf("num = %i -- etage = %i\n\n", num ,etage);
        num++;
    }
    return (0);
}
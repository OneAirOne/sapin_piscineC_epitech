# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/*
* permet de d'afficher un carractere
*  @param : c -> carractere a afficher
*/
void  my_putchar(char c)
{
  write (1,&c,1);
}
/*
* affiche un integer avec les code ascii des char
* @param : nb -> le nombre a afficher
*/
void  my_putnbr(long nb)
{
  long	nb2;
  long	power = 1;

  // Gestion de l'overflow négatif
  // if (nb == -2147483648)
  // {
  //   write(1, "-2147483648", 11);
  // }
  // else
  // {
    // gestion du negatif
    if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
    // determination de la plus grande puissance de 10 de nb pour connaitre le nombre de 0
    while (power <= (nb / 10))
    {
      power = power * 10;
      // printf("niveau = %d\n\n", power);
    }
    // affiche les carractere
    while (power >= 1)
    {
      nb2 = nb / power;
      // printf("nb2 -> %d\n", nb2);
      nb = nb % power;
      // printf("nb -> %d\n", nb);
      power = power / 10;
      // printf("power -> %d\n\n", power);
      my_putchar(nb2 + 48);
    }
  // }
}

int main(int argc, char const *argv[])
{
  long number;
  long divider;
  long res;

  number = atol(argv[1]);
  divider = atol(argv[2]);
  res = number / divider;
  my_putnbr(res);
  my_putchar('\n');

  return (0);
}

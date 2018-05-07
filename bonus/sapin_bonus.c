# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BRIGHTYELLOW  "\x1b[93m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define ANSI_FOND_GREEN   "\x1b[42m"
#define ANSI_FOND_BLUE    "\x1b[44m"



// char deco[6][7] = {
//   "\x1b[31m",
//   "\x1b[32m",
//   "\x1b[33m",
//   "\x1b[34m",
//   "\x1b[35m",
//   "\x1b[36m"
// };

// printf("%s\n",deco[0]);
// int r = rand() % 20;
// my_putstr(deco[0]);







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
void  my_putnbr(int nb)
{
  int	nb2;
  int	power = 1;

  // Gestion de l'overflow négatif
  if (nb == -2147483648)
  {
    write(1, "-2147483648", 11);
  }
  else
  {
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
  }
}
/*
* permet de d'afficher une chaine
*  @param : *str -> chaine a afficher
*/
void  my_putstr(char *str)
{
  int i;
  i = 0;
  while (str[i]  != '\0')
  {
    my_putchar(str[i]);
    i++;
  }
}

/**
* permet de calculer le nombre maximum d'etoile
* en fonction de la taille demandee
* @param : la taille
* @return : le nombre d'etoile max de la derniere ligne
*/
int get_nb_star_last_line(int size)
{
  int x;
  int y;
  int nb_star;
  int level;
  int lost_star_level;

  int offset_x;
  int init_line;
  x = 0;
  y = 0;

  init_line = 4; // nombre ligne de depart du 1er sapin
  nb_star = 0;
  level = 0;
  lost_star_level = 2; // nombre d'etoile retirees a chaque level


  // parcours des niveaux
  while (y < size)
  {
    // parcours des lignes
    while (x < init_line )
    {
      // + 1 etoile pour la premiere ligne puis +2 etoiles toutes les deux lignes
      if (y == 0 && x == 0)
      {
        nb_star = nb_star + 1;
      }
      else if (x != 0)
        nb_star = nb_star + 2;
      // printf("x:%d nb_star:%d\n",x,nb_star);
      x++;
    }

    // actions effectuees a chaque etage
    x = 0;
    init_line++;

    // retrait de 2 etoiles supplementaires tous les 2 niveaux
    if(level == 2)
    {
      level = 0;
      lost_star_level = lost_star_level + 2;
    }
    // IMPORTANT : conditioin special pour retourner le nb_star final
    if (y != (size - 1))
    {
      nb_star = (nb_star - lost_star_level);
    }
    level++;
    y++;
  }
  return(nb_star);
}

/**
* affiche une ligne de structure_sapin
* @param : nombre d'etoile
* @param : nombre d'espace
*/
int print_line(int nb_star, int nb_space)
{
  int x;
  x = 0;
  int space;
  space = 0;
  int random;


  while (x < nb_star)
  {
    while(space < nb_space)
    {
      my_putchar(32);
      space++;
    }
    random  = rand() % 5;
    if (random == 1)
      my_putstr(ANSI_COLOR_RED);
    else if (random == 2)
      my_putstr(ANSI_COLOR_YELLOW);
    else if (random == 2)
      my_putstr(ANSI_COLOR_BRIGHTYELLOW);
    else if (random == 4)
      my_putstr(ANSI_COLOR_BLUE);
    else
      my_putstr(ANSI_COLOR_MAGENTA);


    my_putstr(ANSI_FOND_GREEN);
    my_putchar(42);
    my_putstr(ANSI_COLOR_RESET);
    x++;
  }
  return(space - 1);
}

/*
* cree la structure du sapin et appel la fonction d'affichage a chaque ligne
* @param : taille
* @param : nombre d'espace initiaux sur la premiere ligne
*/
void structure_sapin(int size,int nb_space)
{
  int x;
  int y;
  int nb_star;
  int level;
  int lost_star_level;
  int increase_space;

  int offset_x;
  int init_line;
  x = 0;
  y = 0;

  init_line = 4; // nombre ligne de depart du 1er sapin
  nb_star = 0;
  level = 0;
  lost_star_level = 2; // nombre d'etoile retirees a chaque level
  increase_space = 2; // nombre d'espaces ajoutes a chaque level


  // parcours des niveaux
  while (y < size)
  {
    // printf("y:%d level:%d\n",y, level);
    // parcours des lignes
    while (x < init_line )
    {
      // + 1 etoile pour la premiere ligne puis +2 etoiles toutes les deux lignes
      if (y == 0 && x == 0)
      {
        nb_star = nb_star + 1;
      }
      else if (x != 0)
      {
        nb_star = nb_star + 2;
      }

      // print de la ligne
      nb_space = print_line(nb_star, nb_space);
      // printf("x:%d nb_star:%d\n",x,nb_star);
      // retour a la ligne apres print de chaque ligne
      my_putchar('\n');
      x++;
    }

    // actions effectuees a chaque etage
    x = 0;
    init_line++;

    // retrait de 2 etoiles supplementaires tous les 2 niveaux
    if(level == 2)
    {
      level = 0;
      lost_star_level = lost_star_level + 2;
      increase_space++;
    }
    // retrait des etoile pour la ligne suivante
    nb_star = (nb_star - lost_star_level);

    // ajout d'un espace supplementaire a chaque nouvelle ligne
    nb_space = nb_space + increase_space;
    level++;
    y++;
  }
}

/**
* affiche le tronc
* @param : taille du sapin
* @param : nombre d'etoile maximum sur le bas du sapin
*/
void structure_truk(int size, int nb_star_max)
{
  int x;
  int y;
  x = 0;
  y = 0;
  int nb_pipe;
  int nb_space;
  int space;
  space = 0;

  // calcul du nombre de | en largeur
  if (size % 2 == 0)
  {
    nb_pipe = size + 1;
  }
  else
  {
    nb_pipe = size;
  }

  // determination du nombre d'espace pour centrer le tronc
  nb_space = (nb_star_max - nb_pipe) / 2;

  // affichage des |
  while (y < size)
  {
    while (x < nb_pipe)
    {
      while (space < (nb_space))
      {
        my_putchar(32);
        space++;
      }

      my_putstr(ANSI_COLOR_BLUE);
      my_putstr(ANSI_FOND_BLUE);
      my_putchar('|');
      my_putstr(ANSI_COLOR_RESET);
      x++;
    }
    my_putchar('\n');
    space = 0;
    x = 0;
    y++;
  }
}

void sapin(int size)
{
  int nb_star_max;
  int nb_space;

  // determine le nombre d'etoiles de la derniere ligne
  nb_star_max = get_nb_star_last_line(size);

  // nombre d'espace de la premiere ligne
  nb_space = (nb_star_max / 2);

  // contruit la structure du sapin et affiche les feuilles
  structure_sapin(size, nb_space);

  // construit et affiche le tron
  structure_truk(size, nb_star_max);
}



int main(int argc, char const *argv[])
{
  system("clear");
  // erreur si aucun argement
  if (argc !=  2)
  {
    my_putstr("The argument must be positive.\n");
    exit(-1);
  }
  // erreur si une chaine de carractere non alphanumerique
  if (atoi(argv[1]) ==  0)
  {
    my_putstr("The argument must be positive.\n");
    exit(-1);
  }
  // alphanumerique negatif
  if (atoi(argv[1]) < 0)
  {
    my_putstr("The argument must be positive.\n");
    exit(-1);
  }

  int size;
  int n;
  n = 1;
  int max_n;
  max_n = 100;
  // recuperation de l'arugment
  size = atoi(argv[1]);
  while (n < max_n)
  {
    sapin(size);
    n++;
    // system("sleep 0.5");
    usleep(1000000);
    system("clear");
  }


  return (0);
}


/*
de n 1 jusqu'a 3:
calcul de la taille des lignes pour chaque n
atoi merde = 0
gestioin d'erreur
tout les 2 plateau decalage de ligne
nb espace = valeur max / 2 nb espace 1er ligne

// calcul nb max pour determiner espace et *
// fonction afficher feuillage
// fonctioin tronc


redictioin dans fichier
diff -u text.txt moi.txt
*/

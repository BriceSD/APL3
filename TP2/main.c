#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/*Trouver et programmer la stratégie pour que l’ordinateur gagne tout le temps, argumenter votre choix*/

#define NB_LIGNES 4

void initialiser_plateau_a_zero(int plateau[]){
  for(int i = 0; i < NB_LIGNES; i++){
    plateau[i]=0;
  }
}

void afficher_etat(int plateau[]){
  printf("\n\n");
  for(int i = 0; i<NB_LIGNES; i++){
    printf("%d  ", i);
    if (plateau[i] !=0){
      for(int j = 0; j < plateau[i]; j++){
       printf("| ");
      }
    }
    printf("\n");
  }
  printf("\n\n");
}

void generer_etat(int plateau[], int n){
  initialiser_plateau_a_zero(plateau);

  while(n>0){
    plateau[(rand()%(NB_LIGNES))]++;
    n--;
  }
}

bool est_un_etat_final(int plateau[]){
  for(int i = 0; i < NB_LIGNES; i++){
   if(plateau[i]>0)
      return false;
  }
  return true;
}

bool est_applicable(int plateau[], int ligne, int nb_allum){
  if(nb_allum >= 1 && plateau[ligne] >= nb_allum)
    return true;
  return false;
}

void appliquer (int plateau[], int ligne, int nb_allum){
  if(est_applicable(plateau, ligne, nb_allum))
      plateau[ligne]=plateau[ligne]-nb_allum;
}

int choix_aleatoire_ligne(int plateau[]){
  if(!est_un_etat_final(plateau)){
    int ligne=NULL;
    do{
      ligne=(rand()%NB_LIGNES);
    }while(plateau[ligne]==0);
    return ligne;
  }
  return -1;
}

int choix_aleatoire_nb_allum(int plateau[], int ligne){
  int nb_allum = 0;

  if(plateau[ligne]==0)
    return -1;
  if(plateau[ligne]==1)
    return 1;

  while(nb_allum==0)
    nb_allum=(rand()%plateau[ligne]);

  return nb_allum;
}

void simulation_partie(int plateau[], int nb_allum){
  int ligne = NULL;

  generer_etat(plateau, nb_allum);

  printf("\nDébut de partie simulée\n");
  afficher_etat(plateau);

  while(!est_un_etat_final(plateau)){
    ligne = choix_aleatoire_ligne(plateau);
    nb_allum=choix_aleatoire_nb_allum(plateau, ligne);
    appliquer(plateau, ligne, nb_allum);

    afficher_etat(plateau);
  }
}

bool est_tour_joueur_humain(int tour){
  return (tour % 2 == 0);
}

void vider_buffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int lire_ligne(int plateau[])
{
    int c = 0;

    do
    {
      printf("\n\nChoisissez une ligne : ");
      scanf("%d", &c);
        //c = getchar();
        if(c < 0 || c > NB_LIGNES || plateau[c] < 1)
          printf("\nLa ligne que vous avez choisi n'est pas valide\n");
    }while (c < 0 || c > NB_LIGNES || plateau[c] < 1);
    return c;
}

int lire_nb_allum(int plateau[], int ligne)
{
    int c = 0;
    do
    {
      printf("\n\nChoisissez un nombre d’allumette : ");
      scanf("%d", &c);
        //c = getchar();
        if(c <= 0 || c > plateau[ligne])
          printf("\nLe nombre d'allumettes que vous avez choisi n'est pas valide\n");
    }while (c <= 0 || c > plateau[ligne]);
    return c;
}

void jouer_avec_intelligence ()
{
/*
  calculer la difference en base deux entre toutes les lignes;
  calculer le filtre (plus gros coefficient de la difference);
  calculer le nombre de lignes filtrees;
  tirer au hasard une ligne filtree;
  calculer la valeur a jouer dans cette ligne;
  */
}

void jouer_partie(int plateau[], int nb_allum){
  int tour = -1;
  int choix_ligne=NULL;
  int choix_nb_allum=NULL;
  int ligne=NULL;

  generer_etat(plateau, nb_allum);

  printf("\nDébut de partie\n");
  afficher_etat(plateau);

  while(!est_un_etat_final(plateau)){

    if(est_tour_joueur_humain(++tour)){
      printf("\nC’est au tour du joueur 1\n");
      choix_ligne = lire_ligne(plateau);
      choix_nb_allum = lire_nb_allum(plateau, choix_ligne);
    }
    else{
      printf("\nC’est au tour de l’ordinateur\n");
      choix_ligne = choix_aleatoire_ligne(plateau);
      choix_nb_allum=choix_aleatoire_nb_allum(plateau, choix_ligne);
    }
    appliquer(plateau, choix_ligne, choix_nb_allum);
    afficher_etat(plateau);
  }




}

int main(){
  srand(time(NULL));
  int plateau[NB_LIGNES];
  generer_etat(plateau, 10);
  afficher_etat(plateau);

  //Tests est_un_etat_final
  printf("\nTest est_un_etat_final (attendu 0) : %d\n", est_un_etat_final(plateau));
  for(int i = 0; i < NB_LIGNES; i++){
    plateau[i]=0;
  }
  printf("\nTest est_un_etat_final (attendu 1) : %d\n", est_un_etat_final(plateau));

  //Tests est_applicable
  plateau[0]=4;
  printf("\nTest est_applicable (attendu 0) : %d\n", est_applicable(plateau, 0, 5));
  plateau[1]=4;
  printf("\nTest est_applicable (attendu 1) : %d\n", est_applicable(plateau, 0, 3));
  printf("\nTest est_applicable (attendu 1) : %d\n", est_applicable(plateau, 0, 4));

  //Tests appliquer
  appliquer(plateau, 0, 3);
  printf("\nTest appliquer (attendu 1) : %d\n", plateau[0]);
  appliquer(plateau, 1, 4);
  printf("\nTest appliquer (attendu 0) : %d\n", plateau[1]);

  //Tests choix_aleatoire_ligne
  initialiser_plateau_a_zero(plateau);
  printf("\nTest choix_aleatoire_ligne (attendu -1) : %d\n", choix_aleatoire_ligne(plateau));
  plateau[2]=3;
  printf("\nTest choix_aleatoire_ligne (attendu 2) : %d\n", choix_aleatoire_ligne(plateau));
  plateau[3]=4;
  plateau[1]=4;
  printf("\nTest choix_aleatoire_ligne (attendu 1 ou 2 ou 3) : %d\n", choix_aleatoire_ligne(plateau));

  //Tests choix_aleatoire_nb_allum
  plateau[0]=0;
  printf("\nTest choix_aleatoire_nb_allum (attendu -1) : %d\n", choix_aleatoire_nb_allum(plateau, 0));
  plateau[1]=3;
  printf("\nTest choix_aleatoire_nb_allum (attendu 1 ou 2 ou 3) : %d\n", choix_aleatoire_nb_allum(plateau, 1));
  plateau[2]=1;
  printf("\nTest choix_aleatoire_nb_allum (attendu 1) : %d\n", choix_aleatoire_nb_allum(plateau, 2));


  //Tests simulation_partie
  //simulation_partie(plateau, 12);
  //
  jouer_partie(plateau, 9);
}

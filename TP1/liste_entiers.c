#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Liste *liste;

struct Liste{
  int premier;
  liste suivant;
};

/*Signatures des operations primitives*/
/*issues du type abstrait*/
liste l_vide();
liste cons (int x, liste L);
bool est_vide(liste L);
int prem (liste L);
liste reste (liste L);
/*autres opérations primitives*/
void liberer_liste(liste L);
void ecrire_prem(int x, liste L);
void ecrire_reste(liste R, liste L);

/*Implantation des operations primitives*/
/*Constructeurs*/
liste l_vide(){
  return NULL;
}

liste cons(int x, liste L){
  liste M;
  //Réservation de la place mémoire nécessaire pour une cellule
  M = malloc(sizeof(*M));
  M->premier = x;
  M->suivant = L;
  return M;
}

/*Accès*/
bool est_vide(liste L){
  return L == NULL;
}

int prem(liste L){
  if(est_vide(L)){
    printf("Calcul de prem sur liste vide !\n");
    exit(0);
  }
  return L->premier;
}

liste reste(liste L){
  return L->suivant;
}

/*Autres opérations primitives (hors type-abstrait)*/
void liberer_liste(liste L){
  if (est_vide(L)){
    return ;
  }
  liberer_liste(reste(L));
  free(L);
}

void ecrire_prem(int x, liste L){
  L->premier = x;
}

void ecrire_reste(liste R, liste L){
  L->suivant = R;
}


/*Fonctions ajoutée*/

void afficher_liste(liste L){
  if(est_vide(L)){
    printf("\n");
  }
  else{
   printf("%d ", L->premier);
   afficher_liste(L->suivant);
   }
}

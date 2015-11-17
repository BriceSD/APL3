/************************/
/* test_liste.h         */
/* auteur : Damien Jamet*/
/* version : 2          */
/* date : 03/11/15      */
/************************/

#include "grands_entiers.c"
#include <stdlib.h>

void sep ()
{
  printf ("\n********************\n\n") ;
}

liste liste_test1 ()
{
  return cons (1, cons (2, cons (3, cons (4, l_vide ())))) ;
}


void test_longueur ()
{
  liste L ;
  L = liste_test1 () ;
  printf ("Longueur de ") ;
  afficher_liste (L) ;
  printf (" = %d (R) = %d (I)\n",
	  longueurR (L), longueurI (L)) ;
}

void test_inserer_liste_D_param (unsigned int n, int x, liste L)
{
  printf ("Insertion de %i à la position %u de la liste ",
	  x, n) ;
  afficher_liste (L) ;
  printf("\nRésultat : ") ;
  L = inserer_liste_D (n, x, L) ;
  afficher_liste (L) ;
  printf("\n") ;
}

void test_inserer_liste_D ()
{
  unsigned int n ;
  liste L ;
  for (n = 1 ; n <= 6 ; n = n + 1)
    {
      L = liste_test1 () ;
      test_inserer_liste_D_param (n, 10 * n, L) ;
    }
}

void test_repeter_elements_param (liste L)
{
  printf ("répéter_éléments (") ;
  afficher_liste (L) ;
  printf (") = ") ;
  afficher_liste (repeter_elements (L)) ;
  printf ("\n") ;
}

void test_repeter_elements ()
{
  liste L ;
  L = liste_test1 () ;
  test_repeter_elements_param (L) ;
}

void test_repeter_elements_D ()
{
  liste L ;
  L = cons (1, cons (2, cons (3, l_vide ()))) ;
  printf ("Avant : L = ") ;
  afficher_liste (L) ;
  repeter_elements_D (L) ;
  printf ("\nAprès : L = ") ;
  afficher_liste (L) ;
  printf ("\n") ;
}

void test_sauf_dernier_R(){
  liste L;
  L = liste_test1();
  liste L_test;
  L_test = sauf_dernier_R(L);
  afficher_liste(L_test);
}

void test_sauf_dernier_I(){
  liste L;
  L = liste_test1();
  liste L_test;
  L_test = sauf_dernier_I(L);
  afficher_liste(L_test);
}

void test_afficher_grands_entiers1(){
  liste L;
  L = liste_test1();
  afficher_grands_entiers(L);
}

void test_afficher_grands_entiers2(){
  liste L;
  L = liste_test1();
  L = cons(0,cons(0, L));
  afficher_grands_entiers(L);
}

void test_succ(){
  liste L = liste_test1();
  L = succ(L);
  afficher_grands_entiers(L);
}

void test_entier_vers_grand_entier(){
  liste L ;
  L = entier_vers_grand_entier(4321);
  afficher_grands_entiers(L);
}

void test_grand_entier_vers_entier(){
  int i;
  liste L = liste_test1();
  i = grand_entier_vers_entier(L);
  printf("En entier : %d", i);
}

void test_somme(){
  liste L1 = liste_test1();
  liste L2 = liste_test1();
  liste L3 = somme(L1, L2);
}

int main ()
{
  test_longueur () ;
  sep () ;
  test_inserer_liste_D () ;
  sep () ;
  test_repeter_elements () ;
  sep () ;
  test_repeter_elements_D () ;
  sep();
  test_sauf_dernier_R();
  sep();
  test_sauf_dernier_I();
  sep();
  test_afficher_grands_entiers1();
  sep();
  test_afficher_grands_entiers2();
  sep();
  test_succ();
  sep();
  test_entier_vers_grand_entier();
  sep();
  test_grand_entier_vers_entier();
  sep();
  test_somme();
  sep();
  return EXIT_SUCCESS ;
}

/************************/
/* test_liste.h         */
/* auteur : GUO xuantong*/
/* date : 05/11/15      */
/************************/

#include "liste_grandentier.c"
#include <stdlib.h>

void sep ()
{
  printf ("\n********************\n\n") ;
}

liste liste_test1 ()
{
  return cons (1, cons (2, cons (3, cons (4, l_vide ())))) ;
}

liste liste_test2 ()
{
return (cons (5, cons (9, cons (6, cons (8,cons (0, cons (0, l_vide ()))))))) ;
}

liste liste_test3 ()
{
return (cons (1, cons (1, cons (1, cons (1,cons (0, cons (0, l_vide ()))))))) ;
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

void test_sauf_dernier ()
{
  liste L;
  L = liste_test1 ();
  liste L_test;
  L_test = sauf_dernier(L);
  afficher_liste(L_test);
  printf ("\n") ;
}

void test_sauf_dernier_itteratif ()
{
  liste L;
  L = liste_test1 ();
  liste L_test;
  L_test = sauf_dernier(L);
  afficher_liste(L_test);
  printf ("\n") ;
}

 
void test_afficher_grand_entier()
{
  liste L = liste_test2();
  afficher_grand_entier(L);
}


liste test_succ()
{
  liste L = liste_test2();
  succ(L);
  afficher_liste(succ(L));
}

liste test_entier_vers_grand_entier()
{
  int n = 2125;
  afficher_liste(entier_vers_grand_entier(n));
}

int test_grand_entier_vers_entier()
{
  liste L = liste_test2();
  grand_entier_vers_entier(L);
  printf("%d\n",grand_entier_vers_entier(L));
}

liste test_sommes(liste A,liste B)
{
  afficher_grand_entier(A);
	printf("+");
	afficher_grand_entier(B);
		printf("=");
		afficher_grand_entier(sommes(A,B));
}

liste test_diff(liste A,liste B)
{
  afficher_grand_entier(A);
    printf("-");
	afficher_grand_entier(B);
	  printf("=");
	  afficher_grand_entier(diff(A,B));
}

liste test_produit(liste A,liste B)
{
  afficher_grand_entier(A);
    printf("*");
	afficher_grand_entier(B);
	  printf("=");
	  afficher_grand_entier(produit(A,B));
}


 int main ()
 {
  printf ("longueur: ") ;
  printf ("\n") ;
  test_longueur () ;
  sep () ;
  printf ("inserer_liste_D: ") ;
  printf ("\n") ;
  test_inserer_liste_D () ;
  sep () ;
  printf ("repeter_elements: ") ;
  printf ("\n") ;
  test_repeter_elements () ;
  sep () ;
  printf ("repeter_elements_D: ") ;
  printf ("\n") ;
  test_repeter_elements_D () ;
  printf ("sauf_dernier_récursive: ") ;
  printf ("\n") ;
  test_sauf_dernier () ;
  printf ("sauf_dernier_itteratif: ") ;
  printf ("\n") ; 
  test_sauf_dernier_itteratif () ;


  printf ("afficher_grand_entier: ") ;
  printf ("\n") ;
  test_afficher_grand_entier();
  sep();
  printf ("succ: ") ;
  printf ("\n") ;
  test_succ();
  sep();
  printf ("entier_vers_grand_entier: ") ;
  printf ("\n") ;
  test_entier_vers_grand_entier();
  sep();
  printf ("grand_entier_vers_entier: ") ;
  printf ("\n") ;
  test_grand_entier_vers_entier();
  sep();
  
  liste A = cons (5, cons (9, cons (6, cons (8,cons (0, cons (0, l_vide ()))))));
  liste B = cons (1, cons (1, cons (1, cons (1,cons (0, cons (0, l_vide ()))))));
  printf ("sommes: ") ;
  printf ("\n") ;
  test_sommes(A,B);
  sep();
  printf ("diff: ") ;
  printf ("\n") ;
  test_diff(A,B);
  sep();
  printf ("produit: ") ;
  printf ("\n") ;
  test_produit(A,B);
  sep();
  return EXIT_SUCCESS ;
 }

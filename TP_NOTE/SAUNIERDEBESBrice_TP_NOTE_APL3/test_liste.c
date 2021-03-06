/*************************/
/* liste_entiers.h       */
/* auteur : Damien Jamet */
/* version : 2           */
/* date : 11/02/14       */
/*************************/

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

void test_factoriel(){
  liste L  = entier_vers_grand_entier(100);
  afficher_grand_entier(ecriture_canonique_grand_entier(factoriel(L)));
  printf("\n");
}

void test_nombre_chiffre_paire(){
  liste L = entier_vers_grand_entier(24132811);
  printf("Nombre de chiffre paire dans la liste : ");
  afficher_grand_entier(L);
  printf("\nAttendu 4, obtenu : ");
  afficher_grand_entier(nombre_chiffres_paire(L));
  printf("\n");
}

liste calculer_factoriel_mille(){
  printf("\nCalcul de factoriel 1000, veuillez patienter\n\n");
  liste factoriel_mille =  ecriture_canonique_grand_entier(factoriel(entier_vers_grand_entier(1000)));
  printf ("Factoriel(1000) = ") ;
  afficher_grand_entier(factoriel_mille);
  return factoriel_mille;
}

void longueur_factoriel_mille(liste factoriel_mille){
  printf ("\n Longueur = %d (R); %d (I)\n",
      longueurR(factoriel_mille), longueurI(factoriel_mille)) ;
}

void nombre_chiffres_paire_factoriel_mille(liste factoriel_mille){
  printf ("\nNombre de chiffres paire de factoriel(1000) : ");
  afficher_grand_entier(nombre_chiffres_paire(factoriel_mille));
  printf("\n");
}

void nombre_chiffres_impaire_factoriel_mille(liste factoriel_mille){
  printf ("\nNombre de chiffres impaire de factoriel(1000) : ");
  afficher_grand_entier(nombre_chiffres_impaire(factoriel_mille));
  printf("\n");
}

void somme_chiffres_paire_factoriel_mille(liste factoriel_mille){
  printf ("\nSomme des chiffres paire de factoriel(1000) : ");
  afficher_grand_entier(somme_chiffres_paire(factoriel_mille));
  printf("\n");
}

void somme_chiffres_impaire_factoriel_mille(liste factoriel_mille){
  printf ("\nSomme des chiffres impaire de factoriel(1000) : ");
  afficher_grand_entier(somme_chiffres_impaire(factoriel_mille));
  printf("\n");
}

void test_ppq(){
  liste A = entier_vers_grand_entier(24132811);
  liste B = entier_vers_grand_entier(2213);
  printf("Test ppq (attendu 0) : %d\n",ppq(A,B));
  printf("Test ppq (attendu 1) : %d\n",ppq(B,A));

  liste A2 = entier_vers_grand_entier(24132811);
  liste B2 = entier_vers_grand_entier(24132811);
  printf("Test ppq (attendu 0) : %d\n",ppq(A2,B2));
  printf("Test ppq (attendu 0) : %d\n",ppq(B2,A2));

  liste A3 = entier_vers_grand_entier(24132812);
  liste B3 = entier_vers_grand_entier(24132811);
  printf("Test ppq (attendu 0) : %d\n",ppq(A3,B3));
  printf("Test ppq (attendu 1) : %d\n",ppq(B3,A3));

  liste A4 = l_vide();
  liste B4 = l_vide();
  printf("Deux listes vides\n");
  printf("Test ppq (attendu 0) : %d\n",ppq(A4,B4));
  printf("Test ppq (attendu 0) : %d\n",ppq(B4,A4));
}

void test_max(){
  liste A = entier_vers_grand_entier(24132811);
  liste B = entier_vers_grand_entier(2213);
  printf("Test max (attendu ");
  afficher_grand_entier(A);
  printf(") : ");
  afficher_grand_entier(max(A,B));
  printf("\n");

  printf("Test max (attendu ");
  afficher_grand_entier(A);
  printf(") : ");
  afficher_grand_entier(max(B,A));
  printf("\n");

  liste A2 = entier_vers_grand_entier(24132812);
  liste B2 = entier_vers_grand_entier(24132812);
  printf("Test max (attendu ");
  afficher_grand_entier(A2);
  printf(") : ");
  afficher_grand_entier(max(A2,B2));
  printf("\n");
}

int main (int argc, char** argv)
{

  sep();
  test_factoriel();
  /*
  sep();
  test_nombre_chiffre_paire();
  sep();
  liste factoriel_mille = calculer_factoriel_mille();
  sep();
  longueur_factoriel_mille(factoriel_mille);
  sep();
  nombre_chiffres_paire_factoriel_mille(factoriel_mille);
  sep();
  nombre_chiffres_impaire_factoriel_mille(factoriel_mille);
  sep();
  somme_chiffres_paire_factoriel_mille(factoriel_mille);
  sep();
  somme_chiffres_impaire_factoriel_mille(factoriel_mille);
  */
  sep();
  test_ppq();
  sep();
  test_max();
  sep();

  return EXIT_SUCCESS ;
}

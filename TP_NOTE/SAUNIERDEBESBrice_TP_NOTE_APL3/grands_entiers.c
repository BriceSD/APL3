/*************************/
/* liste_entiers.h       */
/* auteur : Damien Jamet */
/* version : 2           */
/* date : 11/02/14       */
/*************************/

#include "liste_entiers.c"
#include <stdbool.h>

/* question 1*/

#define BASE 10

/* question 2*/

liste sauf_dernier(liste L){
  if (est_vide(reste(L)))
    return l_vide();
  return cons(prem(L),sauf_dernier(reste(L)));
}

int dernier(liste L){
  if (est_vide(reste(L)))
    return prem(L);
  return dernier(reste(L));
}

liste ecriture_canonique_grand_entier(liste L){
  if (dernier(L) != 0)
    return L;
  return ecriture_canonique_grand_entier(sauf_dernier(L));
}

void afficher_grand_entier(liste L){
  if (!est_vide(L)){
    afficher_grand_entier(reste(L));
    printf("%d",prem(L));
  }
}

/* question 3 */
liste succ(liste L){
  if (est_vide(L))
    return cons(1,l_vide());
  if (prem(L) + 1 < BASE)
    return cons(prem(L)+1,reste(L));
  return cons(0,succ(reste(L)));
}

/* question 4 */
liste entier_vers_grand_entier(int n){
  if (n < BASE)
    return cons(n,l_vide());
  return cons(n%BASE,entier_vers_grand_entier(n/BASE));
}

/* question 5 */
int grand_entier_vers_entier(liste L){
  if (est_vide(L))
    return 0;
  return prem(L)+BASE*(grand_entier_vers_entier(reste(L)));
}

/* question 6 */
liste somme(liste A, liste B){
  if ( est_vide(A) )
    return B;
  if ( est_vide(B) )
    return A;
  int r = (prem(A) + prem(B)) % BASE;
  int q = (prem(A) + prem(B)) >= BASE;
  return cons(r,somme( (q == 0)?reste(A):succ(reste(A)),reste(B)));
}

/* question 7 */
int est_nul(liste L){
  if (est_vide(L))
    return 1;
  return (prem(L) == 0) && est_nul(reste(L));
}

liste diff(liste A, liste B){ // TO DO ::: A - B regarder si A<B
  // if (est_nul(A))
  //  return B;
  if (est_nul(B))
    return A;
  if (prem(A) >= prem(B))
    return cons(prem(A) - prem(B),diff(reste(A),reste(B)));
  return cons(BASE + prem(A) - prem(B),diff(reste(A),succ(reste(B))));
}

/* question 8 */
liste produitR(liste A, liste B){ // A x B  version 2
  if (longueurR(A)<longueurR(B))
    return produitR(B,A);
  if ( est_vide(A) || est_vide(B) ){
    return cons(0,l_vide());
  }
  if (longueurR(B) == 1)
    return somme(cons(prem(A)*prem(B) % BASE, l_vide()),
        cons(0,somme(produitR(reste(A),B),
            cons(prem(A)*prem(B) / BASE,l_vide()))));
  return somme(produitR(A, cons(prem(B),l_vide()) ) , cons(0, produitR(A,reste(B))));
}

/* question 9 */
liste factoriel(liste A){ // A - B regarder si A<B
  if (est_nul(A))
    return entier_vers_grand_entier(1);
  return produitR(A,factoriel(diff(A,entier_vers_grand_entier(1))));
}

liste longeur_grand_entier(liste A){
  if(est_vide(A))
    return l_vide();
  return succ(longeur_grand_entier(reste(A)));
}

liste nombre_chiffres_paire(liste A){
  if(est_vide(A))
    return l_vide();
  if(prem(A)%2==0)
    return succ(nombre_chiffres_paire(reste(A)));
  return nombre_chiffres_paire(reste(A));
}

liste nombre_chiffres_impaire(liste A){
  if(est_vide(A))
    return l_vide();
  if(prem(A)%2==1)
    return succ(nombre_chiffres_impaire(reste(A)));
  return nombre_chiffres_impaire(reste(A));
}

liste somme_chiffres_paire(liste A){
  if(est_vide(A))
    return l_vide();
  if(prem(A)%2==0)
    return somme(cons(prem(A),l_vide()),somme_chiffres_paire(reste(A)));
 return somme_chiffres_paire(reste(A));
}

liste somme_chiffres_impaire(liste A){
  if(est_vide(A))
    return l_vide();
  if(prem(A)%2==1)
    return somme(cons(prem(A),l_vide()),somme_chiffres_impaire(reste(A)));
  return somme_chiffres_impaire(reste(A));
}

bool ppq(liste A, liste B){
  if(est_vide(B))
    return false;
  if(est_vide(A))
    return true;

  A = ecriture_canonique_grand_entier(A);
  B = ecriture_canonique_grand_entier(B);

  if (longueurR(A)==longueurR(B)) {
    if (dernier(A)==dernier(B)) {
      if(reste(A)==l_vide() && reste(B)==l_vide())
        return false;
      return ppq(sauf_dernier(A), sauf_dernier(B));
    }
    return dernier(A) < dernier(B);
  }
  return longueurR(A) < longueurR(B);
}

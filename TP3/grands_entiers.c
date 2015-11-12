#include "liste_entiers.c"

void afficher_grands_entiers(liste L){
  if(!est_vide(L)){
    afficher_grands_entiers(reste(L));
    printf("%d", prem(L));
  }
}

liste succ(liste L){
  if(est_vide(L))
    return cons(1, l_vide());
  if(prem(L)+1<BASE)
    return cons(prem(L)+1, reste(L));
  return cons(0, succ(reste(L)));
}

liste entier_vers_grand_entier(int n){
  if(n<BASE)
    return cons(n, l_vide());
  return cons(n%BASE,entier_vers_grand_entier(n/BASE));
}

 

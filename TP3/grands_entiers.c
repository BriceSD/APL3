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

int grand_entier_vers_entier(liste L){
  if(est_vide(L))
    return 0;
  return prem(L)+BASE*(grand_entier_vers_entier(reste(L)));
}

liste somme(liste L1, liste L2){
  if(est_vide(L1))
    return L2;
  if(est_vide(L2))
    return L1;
  int r = (prem(L1)+prem(L2))%BASE;
  int q = (prem(L1)+prem(L2))>=BASE;
  return cons(r,somme((q==0?reste(L1):succ(reste(L1))),reste(L2)));
}

liste difference(liste L1, liste L2){
  if(est_vide(L2))
    return L1;
  if(prem(L1) >= prem(L2))
    return cons(prem(L1)-prem(L2), difference(reste(L1), reste(L2)));
  return cons(BASE+prem(L1)-prem(L2), difference(reste(L1), succ(reste(L2))));
}

//liste multiplication(liste A, liste B){
//  
//}

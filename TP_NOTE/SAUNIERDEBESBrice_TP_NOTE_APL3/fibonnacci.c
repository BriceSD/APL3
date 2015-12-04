#include "grands_entiers.c"

liste fibonacci(int n){
  liste actuel = entier_vers_grand_entier(0);
  liste suivant = entier_vers_grand_entier(1);

  liste tmp;
  while(n--){
    tmp = ecriture_canonique_grand_entier(somme(actuel, suivant));
    actuel = suivant;
    suivant = tmp;
  }
  return actuel;
}

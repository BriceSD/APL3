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

double nb_occurences_fibonacci(liste valeur_fibonacci, int nbr){
  double occurence = 0;


  while(!est_vide(valeur_fibonacci)){
    if(prem(valeur_fibonacci)==nbr)
      occurence ++;
   valeur_fibonacci=reste(valeur_fibonacci);
  }
  return occurence;
}

double frequence_fibonacci(int n){
  liste valeur_fibonacci = fibonacci(n);
  double longueur = longueurI(valeur_fibonacci);

  for(int i = 0; i < 10; i++)
   printf("\nFrequence de %d = %f\n", i, nb_occurences_fibonacci(valeur_fibonacci,i)/longueur);
}

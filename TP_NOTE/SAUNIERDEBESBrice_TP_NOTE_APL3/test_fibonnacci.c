#include "fibonacci.c"
#include <stdlib.h>

void sep (){
  printf ("\n********************\n\n") ;
}

void test_fibonacci(){
  int n;

  n = 0;
  printf("Fibonacci au rang %d, attendu 0, obtenu : ", n);
  afficher_grand_entier(fibonacci(n));
  printf("\n");

  n = 1;
  printf("Fibonacci au rang %d, attendu 1, obtenu : ", n);
  afficher_grand_entier(fibonacci(n));
  printf("\n");

  n = 2;
  printf("Fibonacci au rang %d, attendu 1, obtenu : ", n);
  afficher_grand_entier(fibonacci(n));
  printf("\n");

  n = 4;
  printf("Fibonacci au rang %d, attendu , obtenu : ", n);
  afficher_grand_entier(fibonacci(n));
  printf("\n");

  n = 42;
  printf("Fibonacci au rang %d, attendu 267914296, obtenu : ", n);
  afficher_grand_entier(fibonacci(n));
  printf("\n");
}

void afficher_fibonacci_mille(){
  printf("fibonacci(1000) : ");
  afficher_grand_entier(fibonacci(1000));
  printf("\n");
}

void afficher_longueur_fibonacci_mille(){
  printf("Longueur fibonacci(1000) : ");
  afficher_grand_entier(longeur_grand_entier(fibonacci(1000)));
  printf("\n");
}

void afficher_frequence_fibonacci_mille(){

  printf("Frequences fibonacci(1000) : \n");
  frequence_fibonacci(1000);

}


int main(int argc, char *argv[]){

  sep();
  test_fibonacci();
  sep();
  afficher_fibonacci_mille();
  sep();
  afficher_longueur_fibonacci_mille();
  sep();
  afficher_frequence_fibonacci_mille();
  sep();


  return EXIT_SUCCESS ;
}

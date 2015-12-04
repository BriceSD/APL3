#include "fibonnacci.c"
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


void fibonacci_mille(){

}
int main(int argc, char *argv[]){

  sep();
  test_fibonacci();
  sep();


  return EXIT_SUCCESS ;
}

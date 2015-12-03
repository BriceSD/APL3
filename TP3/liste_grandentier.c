#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



#define BASE 10

typedef struct Liste *liste ;

struct Liste
{
  int premier ;
  liste suivant ;
} ;

/* SIGNATURES DES OPERATIONS PRIMITIVES */
/* issues du type abstrait */
liste l_vide () ;
liste cons (int x, liste L) ;
bool est_vide (liste L) ;
int prem (liste L) ;
liste reste (liste L) ;
/* autres oeérations primitives */
void liberer_liste (liste L) ;
void ecrire_prem (int x, liste L) ;
void ecrire_reste (liste R, liste L) ;

/* IMPLANTATION DES OPERATIONS PRIMITIVES */
/* Constructeurs */
liste l_vide ()
{
  return NULL ;
}

liste cons (int x, liste L)
{
  liste M ;
  // Reservation de la place memoire eécessaire pour une cellule :
  M = malloc (sizeof (*M)) ;
  M->premier = x ; // On peut aussi ecrire " M->premier = x ; "
  M->suivant = L ;
  return M ;
}

/* Accès */
bool est_vide (liste L)
{
  return L == NULL ;
}

int prem (liste L)
{
  if (est_vide (L))
    {
      printf ("Calcul de prem sur liste vide !\n") ;
      exit (0) ;
    }
  return L->premier ;
}

liste reste (liste L)
{
  return L->suivant ;
}

/* Autres operations primitives (hors type-abstrait) */
void liberer_liste (liste L)
{
  if (est_vide (L))
    {
      return ;
    }
  liberer_liste (reste (L)) ;
  free(L) ;
}

void ecrire_prem (int x, liste L)
{
  L->premier = x ;
}

void ecrire_reste (liste R, liste L)
{
  L->suivant = R ;
}

/* OPERATIONS NON PRIMITIVES */
unsigned int longueurR (liste L)
{
  if (est_vide (L))
    return 0 ;
  return 1 + longueurR (reste (L)) ;
}

unsigned int longueurI (liste L)
{
  unsigned int lg ;
  lg = 0 ;
  while (!est_vide (L))
    {
      lg = lg + 1 ;
      L = reste (L) ;
    }
  return lg ;
}

void afficher_liste (liste L)
{
  printf ("(") ;
  while (!est_vide (L))
    {
      printf ("%d%s",
	      prem (L),
	      (est_vide (reste(L)) ? "" : " ")) ;
      L = reste (L) ;
    }
  printf (")") ;
}

liste renverser (liste L)
{
  liste R, M ;
  R = l_vide () ;
  M = L ;
  while (!est_vide(M))
    {
      R = cons (prem(M), R) ;
      M = reste (M) ;
    }
  return R ;
}

/* Operation non destructrice */
liste repeter_elements (liste L)
{
  int x ;
  if (est_vide (L))
    {
      return l_vide () ;
    }
  x = prem (L) ;
  return cons (x, cons (x, repeter_elements (reste(L)))) ;
}

/* Operation destructrice */
void repeter_elements_D (liste L)
{
  int x ;
  if (est_vide (L))
    {
      return ; /* quitter la procedure */
    }
  x = prem (L) ;
  ecrire_reste (cons (x, reste (L)), L) ;
  repeter_elements_D (reste (reste (L))) ;
}

/* Operation pour /modifier/ une liste L en inserant la valeur x
   à la n-ieme position. Sauf dans le cas d'une erreur ou dans le
   cas d'une insertion en première position, cette fonction
   modifie la liste (operation destructrice).
   Si n est trop grand, alors on insere à la fin.
*/
liste inserer_liste_D (unsigned int n, int x, liste L)
{
  unsigned int i ;
  liste M ;
  if (n == 0 || est_vide(L))
    {
      printf ("Utilisation d'inserer_liste_D incorrecte\n") ;
      exit(EXIT_FAILURE) ;
    }
  if (n == 1)
    {
      return cons (x, L) ;
    }
  M = L ;
  i = 1 ;
  while (!est_vide(reste(M)) && i < n - 1) {
      M = reste(M) ;
      i = i + 1 ;
  }
  ecrire_reste (cons(x, reste(M)), M) ;
  return L ;
}

liste sauf_dernier (liste L)
{
  liste L1;
  if (est_vide (L))
    {
      L1==NULL;
    }
  if (longueurI(L) ==1)
    {
      L1==NULL;
    }
  if(longueurI(L) >=2)
    {
      L1= renverser(reste(renverser(L)));
    }

 return L1;
}


liste sauf_dernier_itteratif(liste L)
{
  while (!est_vide(reste(L)))
  {
    L=reste(L);
    if(est_vide(reste(L)))
      {
	return l_vide();
      }
  }
  return cons (L->premier, sauf_dernier(reste(L))) ;
}



/*provoquera l’affichage suivant : 8695*/
void afficher_grand_entier (liste L)
{
  
  if (!est_vide (L))
    {
      afficher_grand_entier(reste(L));
      printf("%d",prem(L));
    }
}


liste succ(liste L)
{
  if (est_vide (L)){
    return (cons(1,l_vide()));
  }
  if (prem(L)+1<BASE){
    return (cons(prem(L)+1,reste(L)));
  }
  return (0,succ(reste(L)));    
}


liste entier_vers_grand_entier(int n)
{
  if (n<BASE)
    return (cons(n,l_vide()));
  return cons(n%BASE,entier_vers_grand_entier(n/BASE));
}


int grand_entier_vers_entier(liste L)
{
  if (est_vide(L))
    {
      return 0;
    }
  return (prem(L)+BASE*(grand_entier_vers_entier(reste(L))));
}

liste sommes(liste A,liste B)
{
  if (est_vide(A)) return B;
  if (est_vide(B)) return A;
  int r=(prem(A)+prem(B))%BASE;
  int q=prem(A)+prem(B)>=BASE;
  return (cons(r,sommes((q==0)?reste(A):succ(reste(A)),reste(B))));
}


liste diff(liste A, liste B)
{
  if(est_vide(B))
    {
      return A;
    }
  if(prem(A)>=prem(B))
    {
      return (cons(prem(A)-prem(B),diff(reste(A),reste(B))));
    }
  return (cons(BASE+prem(A)-prem(B),diff(reste(A),reste(B))));
}


liste produit(liste A,liste B)
{
  if(longueurR (A) < longueurR (B))
    {
      return produit(B,A);
    }
  if(est_vide(A) || est_vide(B))
    {
      return cons(0,l_vide());
    }
  if(longueurR (B)==1)
    {
      return sommes(cons(prem(A)*prem(B)%BASE,l_vide()),cons(0,sommes(produit(reste(A),B),cons(prem(A)*prem(B)/BASE,l_vide()))));
    }
  return sommes(produit(A,cons(prem(B),l_vide())),cons(0,produit(A,reste(B))));
}






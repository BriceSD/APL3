#include "liste_entiers.c"
#include <stdlib.h>
#include <stdbool.h>

#define base 10


bool est_nulI(liste l)
{
    while(!est_vide(l)){
        if (prem(l) != 0)
            return false;
        l = reste(l);
    }
    return true;
}

//recursif
bool est_nul(liste l)
{
    if(est_vide(l))
        return true;
    return (prem(l)==0) && est_nul(reste(l));
}

void afficher_grand_entierI(liste l)
{
    l = renverser(l);
    while(prem(l)==0)
    {
        l = reste(l);
    }

    printf("%d", prem(l));
    while(reste(l) != l_vide())
    {
        l = reste(l);
        printf("%d", prem(l));
    }
    printf("\n");
}

//recu
void afficher_grand_entier(liste l)
{
    if(!est_vide(l))
    {
        afficher_grand_entier(reste(l));
        printf("%d", prem(l));
    }
}

liste succI(liste l)
{
    if (l == l_vide())
    {
        return l_vide();
    }
    int x;
    int y;
    x=prem(l);
    y=x+1;
    if(y>=base)
    {
        return cons(0, succI(reste(l)));
    }
    return cons(y,reste(l));
}

liste succ(liste l)
{
    if(est_nul(l))
        return cons(1, l_vide());
    if(prem(l) == base-1)
        return cons(0, succ(reste(l)));
    return cons(1+prem(l), reste(l));
}

liste entier_vers_grandI(int entier)
{
    liste retour = l_vide();
    int chiffre;
    while(entier > 0)
    {
        chiffre = entier%base;
        entier = entier/10;
        retour = cons(chiffre, retour);        
    }

    return renverser(retour);
}

liste entier_vers_grand(int entier)
{
    if(entier < base)
    {
        return cons(entier, l_vide());
    }
    return cons(entier%base, entier_vers_grand(entier/base));
}

int grand_vers_entier(liste l)
{
    if(est_vide(l))
        return 0;
    return prem(l)+base*(grand_vers_entier(reste(l)));
    
}

liste somme(liste l1, liste l2)
{
    if (est_nul(l1))
        return l2;
    if (est_nul(l2))
        return l1;

    int unite = (prem(l1)+prem(l2))%base;
    int retenue = (prem(l1)+prem(l2))/base;

    if(retenue == 0)
    {
        return cons(unite,somme(reste(l1),reste(l2)));
    }
    return cons(unite,somme(reste(l1),succ(reste(l2))));
}

liste diff(liste l1, liste l2)
{
    if (est_nul(l1))
        return l2;
    if (est_nul(l2))
        return l1;

    if (prem(l1) >= prem(l2))
    {
        int unite = (prem(l1) - prem(l2));
        return cons(unite, diff(reste(l1), reste(l2)));
    }
    return cons(base + prem(l1) - prem(l2), diff(reste(l1), succ(reste(l2))));
}

liste prodI(liste l1, liste l2)
{
    //mult par 0
    if (est_nul(l1) || est_nul(l2))
    {
        return cons(0, l_vide());
    }

    liste iter=l1;

    while(reste(l2)!=l_vide() || prem(l2) != 1)
    {
        l1 = somme(l1, iter);
        l2 = diff(l2, cons(1, l_vide()));
    }

    return l1;
}

//recursif
liste prod(liste l1, liste l2)
{
    if(longueurR(l1)<longueurR(l2))
    {
        return prod(l2,l1);
    }

    if (est_nul(l1)||est_nul(l2))
    {
        return cons(0,l_vide());
    }

    if( longueurR(l2)==1)
    {
        return somme(cons(prem(l1)*prem(l2)%base,l_vide()),cons(0,somme(prod(reste(l1),l2),cons(prem(l1)*prem(l2)/base,l_vide()))));
    }

  return somme(prod(l1,cons(prem(l2),l_vide())),cons(0,prod(l1,reste(l2))));
}

liste facto(liste l)
{
    if(est_nul(l))
        return cons(1, l_vide());

    return prod(facto(diff(l, cons(1, l_vide()))), l);
}

liste sauf_dernier(liste l)
{
    if(reste(l)==l_vide())
    {
        return l_vide();
    }
    return cons(prem(l), sauf_dernier(reste(l)));
}

int dernier(liste l)
{
    if (reste(l) == l_vide())
        return prem(l);
    return dernier(reste(l));
}

bool plus_petit_que(liste l1, liste l2)
{
    if (longueurR(l1)==longueurR(l2))
    {
        if (dernier(l1)==dernier(l2))
        {
            if(reste(l1)==l_vide() && reste(l2)==l_vide())
                return false;
            return plus_petit_que(sauf_dernier(l1), sauf_dernier(l2));
        }
        return dernier(l1) < dernier(l2);
    }
    return longueurR(l1) < longueurR(l2);
}


//ne peux pas calculer un quotient plus grand que 258048
liste quotient(liste a, liste b)
{
    if(plus_petit_que(a, b))
        return cons(0, l_vide());

    return succ(quotient(diff(a, b), b));
}
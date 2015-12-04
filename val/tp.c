#include "ex2.c"

int nombre_chiffres_pairs(liste l){
    if (est_vide(l))
    {
        return 0;
    }
    int x = prem(l);

    if(x%2==0){
        return 1 + nombre_chiffres_pairs(reste(l));
    }
    else{
        return 0 + nombre_chiffres_pairs(reste(l));
    }
}
int nombre_chiffres_impairs(liste l){
    if (est_vide(l))
    {
        return 0;
    }
    int x = prem(l);

    if(x%2==0){
        return 0 + nombre_chiffres_impairs(reste(l));
    }
    else{
        return 1 + nombre_chiffres_impairs(reste(l));
    }
}

void somme_chiffres(liste l){
    int i = 0;
    int pair = 0;
    int impair = 0;

    while(!est_vide(l)){
        if(i%2==0){
            pair += prem(l);
        }
        else{
            impair += prem(l);
        }
        i++;
        l = reste(l);
    }
    printf("Somme des chiffres de rang pairs : %i\n", pair);
    printf("Somme des chiffres de rang impairs : %i\n", impair);
}

liste max(liste l1, liste l2)
{
    if (plus_petit_que(l1, l2))
    {
        return l2;
    }
    return l1;
}

liste fibo(int rang)
{
    liste fx = entier_vers_grand(1);
    liste fx1 = entier_vers_grand(1);
    liste temp;
    int i;

    for (i = 1; i < rang; i++)
    {
        temp = somme(fx, fx1);
        fx = fx1;
        fx1 = temp;
    }
    return fx;

}

//renvoie le nb d'apparitions de x dans la liste l
int nb_occurence(liste l, int x){
    int nb = 0;
    while(!est_vide(l)){
        if(prem(l) == x){
            nb++;
        }
        l = reste(l);
    }
    return nb;
}

//affiche la fréquance d'occurence de tous les chiffres
void freq_occurence(liste l){
    int i;
    double freq;
    double longueur = longueurR(l);
    for (i = 0; i < 10; i++)
    {
        freq = nb_occurence(l, i)/longueur;
        printf("freq d'occurence de %i = %f\n", i, freq);
    }
}

liste modulo(liste l1, liste l2){
    return l1;
}

liste division(liste l1, liste l2){
    liste quotient = l_vide();
    liste reste = l1;

    while(plus_petit_que(l2, reste)){

    }
    return quotient;
}

bool est_premier(liste l)
{
    liste n = entier_vers_grand(2);
    return true;
}

liste plus_grand_diviseur(liste l)
{
    liste diviseur = diff(l, entier_vers_grand(1));
    while(!est_nul(diviseur)){
        if(est_nul(modulo(l, diviseur))){
            return diviseur;
        }
        diviseur = diff(diviseur, entier_vers_grand(1));
    }

    return l_vide();
}

int main(int argc, char const *argv[])
{
    // liste l1 = entier_vers_grand(1000);
    // liste l2 = facto(l1);

    // afficher_grand_entier(l2);

    // printf("\nNombre de chiffres de factorielle 1000 : %i\n", longueurR(l2));
    // printf("Nombre de chiffres pairs de factorielle 1000 : %i\n", nombre_chiffres_pairs(l2));
    // printf("Nombre de chiffres impairs de factorielle 1000 : %i\n", nombre_chiffres_impairs(l2));

    // somme_chiffres(l2);

    // liste l3 = entier_vers_grand(987);
    // liste l4 = entier_vers_grand(989);

    // printf("987 ppq 989 ? %i\n", plus_petit_que(l3, l4));

    // printf("Maximum de 987 et 989 :");
    // afficher_grand_entier(max(l4, l3));
    // printf("\n");

    // printf("fibo %i :", 1000);
    // liste l5 = fibo(1000);
    // afficher_grand_entier(l5);
    // printf("\n");

    // printf("Longueur de f(1000) : %i\n", longueurR(l5));
    // freq_occurence(l5);

    liste l6 = fibo(10000);
    afficher_grand_entier(l6);
    printf("\n");

    // liste l8 = entier_vers_grand(1234005678);
    // liste l7 = entier_vers_grand(2500000);
    // afficher_grand_entier(modulo(l8, l7));
    printf("\n");

    return 0;
}

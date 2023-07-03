#include "listechainee.h"

///Constructeur

listeChainee liste_vide(){
    listeChainee l = {NULL, 0};
    return l;
}

///Destructeur

void maillon_detruire(maillon *cible){
    if (cible == NULL) {return;} //cas de base
    maillon_detruire(cible->suivant); //recursivite sur la longueur de la chaine
    free(cible);
}

void liste_detruire(listeChainee *cible){
    maillon_detruire(cible->chaine); //destruction des ressources
    cible->taille = 0; //reinitialisation
    cible->chaine = NULL;
}

///Etat

int liste_etat(listeChainee *l){
    return (l == NULL || l->chaine == NULL) ? 0 : 1;
}

///Accesseur


/** \brief fonction d'usage generique pour recuperer un maillon a la position donnee
 *
 */
maillon* maillon_acces(maillon* m, unsigned int i){
    if (m == NULL) {return NULL;} //prog defensive
    if (i == 0) {return m;}
    return maillon_acces(m->suivant, i-1);
}

TYPE* liste_acces(listeChainee *l, unsigned int i){
    if (l == NULL || i >= l->taille) {return NULL;} //verification de l'existence
    maillon* cible = maillon_acces(l->chaine, i); //consultation recursive
    return (cible == NULL) ? NULL : &(cible->valeur); //on recupere la valeur en verifiant qu'elle est valide
}

///Insertion

/** \brief fonction qui renvoie un pointeur sur le pointeur designant le noeud en position i, si il existe
 *         Un cas limite est la position taille, qui correspond a NULL. Dans ce cas, renvoie le pointeur
 *         sur NULL du dernier noeud de la liste.
 */
maillon** maillon_recuperer_parent(listeChainee *l, unsigned int i){
    if (l == NULL || i > l->taille) {return NULL;}
    maillon** papa = NULL;
    if (i==0) {
        papa = &(l->chaine);
    }else {
        maillon* prec = maillon_acces(l->chaine, i-1);
        if (prec == NULL) {return NULL;}
        papa = &(prec->suivant);
    }
    return papa;
}

int liste_insere(listeChainee *l, unsigned int i, TYPE valeur){
    //recuperation du pointeur visant le maillon
    maillon** papa = maillon_recuperer_parent(l, i);
    if (papa == NULL) {
        return 1;
    }
    //creation du nouveau noeud
    maillon* nouveau = (maillon*)malloc(sizeof(maillon));
    if (nouveau == NULL) {return 2;}
    nouveau->valeur = valeur;
    //assignation
    nouveau->suivant = *papa; //on fait pointer le nouuveau noeud sur le successeur
    *papa = nouveau; //et on informe le pere qu'il a un nouveau fils
    l->taille++;
    return 0;
}


///Suppression

int liste_supprime(listeChainee *l, unsigned int i){
    maillon** papa = maillon_recuperer_parent(l, i);
    if (papa == NULL || *papa == NULL) {
        return 1;
    }
    maillon* tmp = *papa;
    *papa = (*papa)->suivant;
    free(tmp);
    l->taille--;
    return 0;
}

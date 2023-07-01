#ifndef LISTECHAINEE_H_INCLUDED
#define LISTECHAINEE_H_INCLUDED

#include <stdlib.h>

#include "param.h"

/** Declarations **/

///declaration des types de donnees

typedef struct s_maillon {
    struct s_maillon *suivant;
    TYPE valeur;
} maillon;

typedef struct {
    maillon *chaine;
    size_t taille;
} listeChainee;


///fonctions de manipulation

/** \brief Cree une liste initialisee vide, de taille 0
 */
listeChainee liste_vide();


/** \brief Libere les ressources consommees par la liste
 */
void liste_detruire(listeChainee *cible);


/** \brief Renvoie un pointeur sur la valeur de l'element d'index i,
 *         si il existe. Renvoie NULL sinon.
 */
TYPE* liste_acces(listeChainee *l, unsigned int i);


/** \brief Essaye d'inserer un element en la position i, si possible
 *  \return 0 en cas de reussite
 *          1 si la position precise est invalide (i peut aller de 0 a la taille de la liste [pour le dernier])
 *          2 en cas d'echec d'allocation de memoire (malloc renvoie NULL)
 *          Si le retour n'est pas 0, la liste n'a pas ete modifiee
 */
int liste_insere(listeChainee *l, unsigned int i, TYPE valeur);


/** \brief Essaye de supprimer l'element en position i, si possible (libere la memoire)
 *  \return 0 en cas de reussite
 *          1 si la position precise est invalide (i peut aller de 0 a la taille de la liste - 1)
 *          Si le retour n'est pas 0, la liste n'a pas ete modifiee
 */
int liste_supprime(listeChainee *l, unsigned int i);

#endif // LISTECHAINEE_H_INCLUDED

#ifndef PILESFILES_H_INCLUDED
#define PILESFILES_H_INCLUDED

#include "listechainee.h"

typedef listeChainee pile; //les piles sont simplement une liste chainee particuliere
typedef listeChainee file; //de meme pour les files

///Piles

/** \brief Cree une pile vide
 */
pile pile_vide();


/** \brief Detruit une pile
 */
void pile_detruire(pile* p);


/** \brief Renvoie 0 si la pile est vide, 1 sinon
 */
int pile_etat(pile *p);


/** \brief Renvoie la valeur du premier element de la pile sans modifier la pile
 *         Si l'element n'existe pas, la fonction renvoie une valeur par defaut
 *         Cette valeur est specifiee en parametre.
 */
TYPE pile_consulter(pile *p, TYPE defaut);


/** \brief La fonction ci-dessous est un raccourci pour "pile_consulter(p, 0)",
 *         Si TYPE n'est pas initialisable a 0 (si ce n'est pas un type numerique),
 *         alors cette fonction doit etre desimplemente pour eviter une erreur de
 *         compilation
 */
TYPE pile_consulter_d(pile *p);


/** \brief Renvoie la valeur et supprimme le premier element de la pile
 *         Renvoie une valeur par defaut (cf. ci dessus) si la pile est invalide.
 *         La pile ne sera pas modifiee en ce cas.
 */
TYPE pile_depiler(pile *p, TYPE defaut);


/** \brief La fonction ci-dessous est un raccourci pour "pile_depiler(p, 0)",
 *         Si TYPE n'est pas initialisable a 0 (si ce n'est pas un type numerique),
 *         alors cette fonction doit etre desimplemente pour eviter une erreur de
 *         compilation
 */
TYPE pile_depiler_d(pile *p);


/** \brief Ajoute un element la pile
 *  \return 0 en cas de reussite, 1 sinon
 *          Si le retour n'est pas 0, la pile n'a pas ete modifiee
 */
int pile_empiler(pile *p, TYPE valeur);

 ///Files

 /** \brief Cree une file vide
 */
file file_vide();


/** \brief Detruit une file
 */
void file_detruire(file* f);


/** \brief Renvoie 0 si la file est vide, 1 sinon
 */
int file_etat(file *f);


/** \brief Renvoie la valeur du premier element de la file sans modifier la file
 *         Si l'element n'existe pas, la fonction renvoie une valeur par defaut
 *         Cette valeur est specifiee en parametre.
 */
TYPE file_consulter(file *f, TYPE defaut);


/** \brief La fonction ci-dessous est un raccourci pour "file_consulter(p, 0)",
 *         Si TYPE n'est pas initialisable a 0 (si ce n'est pas un type numerique),
 *         alors cette fonction doit etre desimplemente pour eviter une erreur de
 *         compilation
 */
TYPE file_consulter_d(file *f);


/** \brief Renvoie la valeur et supprimme le premier element de la file
 *         Renvoie une valeur par defaut (cf. ci dessus) si la file est invalide.
 *         La file ne sera pas modifiee en ce cas.
 */
TYPE file_defiler(file *f, TYPE defaut);


/** \brief La fonction ci-dessous est un raccourci pour "file_defiler(p, 0)",
 *         Si TYPE n'est pas initialisable a 0 (si ce n'est pas un type numerique),
 *         alors cette fonction doit etre desimplemente pour eviter une erreur de
 *         compilation
 */
TYPE file_defiler_d(file *f);


/** \brief Ajoute un element la file
 *  \return 0 en cas de reussite, 1 sinon
 *          Si le retour n'est pas 0, la file n'a pas ete modifiee
 */
int file_enfiler(file *f, TYPE valeur);


#endif // PILESFILES_H_INCLUDED

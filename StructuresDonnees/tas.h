#ifndef TAS_H_INCLUDED
#define TAS_H_INCLUDED

#include <stdlib.h>

#include "param.h"

typedef struct {
    TYPE* donnees;
    size_t taille;
    size_t capacite;
} tas_min;


/** \brief Cree un tas vide, de capacite specifie. Si la capacite est
 *         trop grande, les donnees seront initialisees a NULL.
 */
tas_min tas_vide(size_t capacite);


/** \brief Libere les ressources consommees par le tas
 */
void tas_detruire(tas_min *t);


/** \brief Creer un tas a partir d'un tableau (utilise l'espace memoire du tableau)
 */
tas_min tas_creer(TYPE* donnees, size_t nombre);


/** \brief Change la capacite du tas
 *  \return 0 en cas de reussite, 1 sinon
 */
int tas_change_capacite(tas_min *t, size_t nouvelle);


 /** \brief Ajoute une valeur au tas
  *  \return 0 en cas de reussite, 1 sinon
  */
int tas_insere(tas_min *t, TYPE valeur);


/** \brief Renvoie la valeur du minimum du tas sans le modifier
 *         Si l'element n'existe pas, la fonction renvoie une valeur par defaut
 *         Cette valeur est specifiee en parametre.
 */
TYPE tas_consulter(tas_min *t, TYPE defaut);


/** \brief La fonction ci-dessous est un raccourci pour "tas_consulter(t, 0)",
 *         Si TYPE n'est pas initialisable a 0 (si ce n'est pas un type numerique),
 *         alors cette fonction doit etre desimplemente pour eviter une erreur de
 *         compilation
 */
TYPE tas_consulter_d(tas_min *t);


/** \brief Supprimme et renvoi la racine du tas
 *         Si l'element n'existe pas, la fonction renvoie une valeur par defaut
 *         Cette valeur est specifiee en parametre.
 */
TYPE tas_extraire(tas_min *t, TYPE defaut);


/** \brief La fonction ci-dessous est un raccourci pour "tas_extraire(t, 0)",
 *         Si TYPE n'est pas initialisable a 0 (si ce n'est pas un type numerique),
 *         alors cette fonction doit etre desimplemente pour eviter une erreur de
 *         compilation
 */
TYPE tas_extraire_d(tas_min *t);

#endif // TAS_H_INCLUDED

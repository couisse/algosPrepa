#include <string.h>

#include "tas.h"
int tas_idx_gauche(int index){
    return (index == 0) ? 1 : index << 1; //l'index du fils gauche est index * 2 (multiplication par decalage)
}

int tas_idx_droit(int index){
    return (index == 0) ? 2 : ((index << 1) | 1); //l'index du fils droit est index * 2 + 1
}

int tas_idx_parent(int index){
    return index >> 1; //l'index du parent est index / 2
}

tas_min tas_vide(size_t capacite)
{
    tas_min t = {NULL, 0, capacite};
    t.donnees = (TYPE*)malloc(sizeof(TYPE) * capacite);
    if (t.donnees == NULL){t.capacite = 0;}
    return t;
}

void tas_detruire(tas_min *t)
{
    if (t == NULL || t->donnees == NULL) {return;}
    free(t->donnees);
    t->taille = 0;
    t->capacite = 0;
}

int tas_change_capacite(tas_min *t, size_t nouvelle){
    if (t == NULL || nouvelle < t->taille) {return 1;}
    //reservation de la memoire
    TYPE* nouvelles_donnes = (TYPE*)malloc(nouvelle * sizeof(TYPE));
    if (nouvelles_donnes == NULL){return 1;}
    //copie - collage des anciennes donnees
    memcpy(nouvelles_donnes, t->donnees, sizeof(TYPE) * t->taille);
    free(t->donnees);
    t->donnees = nouvelles_donnes;
    t->capacite = nouvelle;
    return 0;
}

/** \brief Augmentation de la taille du tas en cas de débordement
 */
int tas_augmenter(tas_min *t){
    if (t == NULL) {return 1;}
    //multiplication de la capacite par 1.5 (cf librairie standard)
    //2 points fixes sont 0 et 1, que l'on traite separement
    size_t nouvelle_taille = (t->capacite <= 1) ? 8 : t->capacite + (t->capacite >> 1);
    return tas_change_capacite(t, nouvelle_taille);
}

/** \brief Cette fonction est auxiliaire a tas_insere et sert à retablir
 *         la propriete du tas min lors de l'insertion
 */
void tas_remonter_noeud(TYPE* t, int index){
    int prec = tas_idx_parent(index);
    if (t[prec] > t[index]){ //si la propriete du tas min n'est pas verifiee
        int tmp = t[index];
        t[index] = t[prec];
        t[prec] = tmp;
        tas_remonter_noeud(t, prec);
    }
}

int tas_insere(tas_min *t, TYPE valeur){
    if (t == NULL){return 1;}
    if (t->taille >= t->capacite){
        if (tas_augmenter(t) != 0) {return 1;}
        return tas_insere(t, valeur);
    }
    t->donnees[t->taille] = valeur; //on insere le nouveau noeud en feuille
    tas_remonter_noeud(t->donnees, t->taille); //et on le fait remonter jusqu'a retablissement de la propriete du tas
    t->taille++;
    return 0;
}

TYPE tas_consulter(tas_min *t, TYPE defaut){
    if (t == NULL || t->donnees == 0 || t->donnees == NULL) {return defaut;}
    return t->donnees[0];
}

TYPE tas_consulter_d(tas_min *t){
    return tas_consulter(t, 0); //cf doc en cas d'erreur de compilation
}

/** \brief Cette fonction est auxiliaire a tas_extraire et sert à retablir
 *         la propriete du tas min lors de la suppression
 */
void tas_descendre_noeud(tas_min* t, int index){

    int gauche = tas_idx_gauche(index);
    int droite = tas_idx_droit(index);

    //as relatif a l'arrivee a un noeud qui a une descendance
    if (gauche < t->taille){
        if (droite < t->taille && t->donnees[gauche] > t->donnees[droite]){ //2 enfants
            t->donnees[index] = t->donnees[droite];
            tas_descendre_noeud(t, droite);
        }else { //seulement un fils de gauche (ne peut avoir uniquement un fils de droite)
            t->donnees[index] = t->donnees[gauche];
            tas_descendre_noeud(t, gauche);
        }
    }else { //Arrivee a une feuille, on retablit la propriete en remplacant le noeud
        t->donnees[index] = t->donnees[t->taille-1];
        tas_remonter_noeud(t->donnees, index);
    }
}

TYPE tas_extraire(tas_min *t, TYPE defaut){
    if (t == NULL || t->taille == 0 || t->donnees == NULL) {return defaut;}
    TYPE valeur = t->donnees[0];
    tas_descendre_noeud(t, 0);
    t->taille--;
    return valeur;
}

TYPE tas_extraire_d(tas_min *t){
    return tas_extraire(t, 0);
}

/** \brief Cette fonction est auxiliaire a tas_creer et sert a creer les sous-tas
 */
void entasser(tas_min *t, int index){
    int gauche = tas_idx_gauche(index);
    int droite = tas_idx_droit(index);
    int min;
    //recherche de l'indice du minimum
    if (gauche < t->taille && t->donnees[index] > t->donnees[gauche]){
        min = gauche;
    }else {
        min = index;
    }
    if (droite < t->taille && t->donnees[min] > t->donnees[droite]){
        min = droite;
    }
    //mise du minimum en haut et appel recursif
    if (min != index){
        int tmp = t->donnees[index];
        t->donnees[index] = t->donnees[min];
        t->donnees[min] = tmp;
        entasser(t, min);
    }
}

tas_min tas_creer(TYPE* donnees, size_t nombre){
    tas_min t = {donnees, nombre, nombre};
    for (int i = nombre/2; i >= 0; i--){
        entasser(&t, i);
    }
    return t;
}

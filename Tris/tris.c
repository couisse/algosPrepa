#include "tris.h"

void tris_tas(TYPE* donnees, size_t nombre){
    tas_max t = tas_creer(donnees, nombre);
    TYPE valeur;
    for (unsigned int i = nombre-1; i >= 1; i--){ //nombre-1 extractions
        valeur = tas_extraire_d(&t);
        donnees[i] = valeur;
    }
}

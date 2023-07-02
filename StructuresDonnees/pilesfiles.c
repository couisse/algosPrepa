#include "pilesfiles.h"

///PILES

pile pile_vide(){
    return liste_vide();
}

void pile_detruire(pile *p){
    liste_detruire(p);
}

int pile_etat(pile *p){
    return liste_etat(p);
}

TYPE pile_consulter(pile *p, TYPE defaut){
    if (pile_etat(p) == 0){
        return defaut;
    }
    return p->chaine->valeur;
}

TYPE pile_consulter_d(pile *p){
    return pile_consulter(p, 0); //cf doc en cas d'erreur de compilation
}

TYPE pile_depiler(pile *p, TYPE defaut){
    if (pile_etat(p) == 0){
        return defaut;
    }
    TYPE valeur = p->chaine->valeur;
    p->chaine = p->chaine->suivant;
    p->taille--;
    return valeur;
}

TYPE pile_depiler_d(pile *p){
    return pile_depiler(p, 0); //cf doc en cas d'erreur de compilation
}

int pile_empiler(pile *p, TYPE valeur){
    return (liste_insere(p, 0, valeur) == 0) ? 0 : 1;
}

///FILES

file file_vide(){
    return liste_vide();
}

void file_detruire(file *f){
    liste_detruire(f);
}

int file_etat(file *f){
    return liste_etat(f);
}

TYPE file_consulter(file *f, TYPE defaut){
    if (file_etat(f) == 0){
        return defaut;
    }
    return f->chaine->valeur;
}

TYPE file_consulter_d(file *p){
    return file_consulter(p, 0); //cf doc en cas d'erreur de compilation
}

TYPE file_defiler(file *f, TYPE defaut){
    if (file_etat(f) == 0){
        return defaut;
    }
    TYPE valeur = f->chaine->valeur;
    f->chaine = f->chaine->suivant;
    f->taille--;
    return valeur;
}

TYPE file_defiler_d(file *f){
    return file_defiler(f, 0); //cf doc en cas d'erreur de compilation
}

int file_enfiler(file *f, TYPE valeur){
    return (liste_insere(f, f->taille, valeur) == 0) ? 0 : 1;
}

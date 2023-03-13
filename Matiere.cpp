#ifndef MATIERE_CPP
#define MATIERRE_CPP
#include "Matiere.h"

Matiere::Matiere(string nom, double coef){
    this->nom = nom;
    this->coef = coef;
}

void Matiere::setNom(string nom){
    this->nom = nom;
}
void Matiere::setCoef(double coef){
    this->coef = coef;
}
void Matiere::addNote(double note){
    this->note.push_back(note);
    //calcul de la nouvelle moyenne
    this->moyenne = getMoyenne();
}

double Matiere::getMoyenne(){
    
    double totalNote = 0;

    for(int i = 0; i < note.size(); i++){
        totalNote += note[i];
    }
    return (double)totalNote/note.size();
}

string Matiere::getNom(){
    return this->nom;
}

Matiere::~Matiere(){}
#endif
#ifndef UE_H
#define UE_H
#include "header.h"
#include "matiere.h"

class Ue{
    private:
    string nom;
    vector<Matiere> matiere;

    public:
    //constructeur,destructeur
    Ue(string nom);
    ~Ue();
    
    //geteur
    string getNom();
    
    //setteur
    void setNom(string nom);
    //méthode matière
    
    int calcul_moyenne();
    
    
};
#endif
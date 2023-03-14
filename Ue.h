#ifndef UE_H
#define UE_H
#include "header.h"
#include "matiere.h"

class Ue{
    private:
    std::string nom;
    std::vector<Matiere> matiere;

    public:
    //constructeur,destructeur
    Ue(std::string nom);
    ~Ue();
    
    //geteur
    std::string getNom();
    
    //setteur
    void setNom(std::string nom);
    //méthode matière
    
    int calcul_moyenne();
    
    
};
#endif
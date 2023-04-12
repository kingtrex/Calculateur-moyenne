#ifndef UE_H
#define UE_H
#include "header.h"

class Ue{
    private:
    std::string nom;

    public:
    //constructeur,destructeur
    Ue(std::string nom): nom(nom){}
    ~Ue(){};
    
    //geteur
    std::string getNom(){return this->nom;}    
    //setteur
    void setNom(std::string nom){this->nom = nom;}
    //méthode matière
    
    
};
#endif
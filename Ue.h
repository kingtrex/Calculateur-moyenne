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
    Ue(std::string nom): nom(nom){}
    ~Ue();
    
    //geteur
    std::string getNom() {return this->nom;}
    std::vector<std::string> getMatiere();
    
    //setteur
    void setNom(std::string nom) {this->nom = nom;};
    //méthode matière
    
    int calculMoyenne();
    
};
#endif
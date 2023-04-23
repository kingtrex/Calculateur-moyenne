#ifndef UE_H
#define UE_H
#include "header.h"
class Ue{
    private:
    std::string nom;
    double moyenne;
    
    public:
    //constructeur,destructeur
    Ue(std::string nom): nom(nom){verifNom();}
    ~Ue(){};
    
    //geteur
    std::string getNom()const {return this->nom;}    
    double getMoyenne()const {return this->moyenne;}

    //setteur
    void setNom(std::string nom);
    void setMoyenne(double moyenne){this->moyenne = moyenne;}

    //méthode matière
    void verifNom();
    void verifSaisie(double &var, int min, int max);
    void verifSaisie(int &var, int min, int max);

};
#endif
#ifndef MATIERE_H
#define MATIERE_H
#include "header.h"



class Matiere: public Ue{
    private:
    
    double coef;
    std::vector<Note> note;
    double moyenne;

    public:
    Matiere(std::string nom, double coef): Ue(nom), coef(coef){}
    ~Matiere();

    void setCoef(double coef);
    void addNote(double note, double pourcentage);

    double getMoyenne();
    std::string getNom();
    double getCoef(){return this->coef;}
};
#endif
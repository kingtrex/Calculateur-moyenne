#ifndef MATIERE_H
#define MATIERE_H
#include "header.h"
#include "Ue.h"
#include "Note.h"

class Matiere: public Ue 
{
    private:
    
    double coef;
    std::vector<Note> note;
    Ue &lien;

    public:
    Matiere(std::string nom, double coef, Ue &lien): Ue(nom), coef(coef), lien(lien){}
    ~Matiere(){};

    void setCoef(double coef);
    void addNote(double note, double pourcentage, std::string label);

    double getCoef(){return this->coef;}
    void getNote();
    std::string getUe(){return this->lien.getNom();}
    int getTotalPourcentage();
    void saveNote(std::ofstream &file);
    void verifPourcentage();
    void reparNote();
    double calculMoyenne();
    double calculMoyenne(std::vector<Matiere> matiere, std::string nom);
};
#endif
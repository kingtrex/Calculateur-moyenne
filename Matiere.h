/****************************************************************************************************
 *                                    Projet: calculateur de moyenne                                *
 *                                    Auteur: Thibault TANNÉ                                        *
 *                                          18/05/2023                                              *
*****************************************************************************************************/
#ifndef MATIERE_H
#define MATIERE_H
#include "header.h"
#include "Ue.h"
#include "Note.h"

class Matiere: public Ue 
{
    public:
    Matiere(const std::string &nom, double coef, Ue &lien): Ue(nom), coef(coef), lien(lien){}
    Matiere(const std::string &nom, double coef): Ue(nom), coef(coef){}
    ~Matiere(){};

    void setCoef(double coef);
    void addNote(double note, double pourcentage, const std::string &label);

    double getCoef()const {return this->coef;}
    void getNote();
    std::string getUe()const {return this->lien.getNom();}
    int getTotalPourcentage();
    int getNbNote()const {return this->note.size();}

    void saveNote(std::ofstream &file);
    void verifPourcentage();
    void verifMoyenne();
    void reparNote();
    void afficheNote(int action);
    void modifMatiere(int action);
    int noteIdeale();
    void calculMoyenne();
    double calculMoyenne(std::vector<Matiere> matiere, std::string nom);
    double calculMoyenne(std::vector<Note> note);
    
    private:
    double coef;
    std::vector<Note> note;
    Ue lien;

    


};
#endif
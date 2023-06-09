/****************************************************************************************************
 *                                    Projet: calculateur de moyenne                                *
 *                                    Auteur: Thibault TANNÉ                                        *
 *                                          18/05/2023                                              *
*****************************************************************************************************/
#ifndef NOTE_H
#define NOTE_H
#include "header.h"
#include "Ue.h"
class Note: public Ue{

    public:
    //constructeur/destructeur
    Note(double note, double pourcentage): note(note), pourcentage(pourcentage){}
    Note(double note, double pourcentage, std::string label): Ue(label), note(note), pourcentage(pourcentage){}
    ~Note(){}
    
    //get/set
    double getNote(){return this->note;}
    int getPourcentage(){return this->pourcentage;}
    
    void setNote(double note){this->note = note;}
    void setPourcentage(int pourcentage){this->pourcentage = pourcentage;}

    //methode diverse
    std::string getData();
    void modifNote();

    private:
    double note;
    int pourcentage;
};


#endif
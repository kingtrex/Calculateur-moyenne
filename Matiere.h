#ifndef MATIERE_H
#define MATIERE_H
#include "header.h"
#include <string>


class Matiere{
    private:
    std::string nom;
    double coef;
    std::vector<double> note;
    double moyenne;

    public:
    Matiere(std::string nom, double coef);
    ~Matiere();

    void setNom(std::string nom);
    void setCoef(double coef);
    void addNote(double note);

    double getMoyenne();
    std::string getNom();
};
#endif
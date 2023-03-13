#ifndef MATIERE_H
#define MATIERE_H
#include "header.h"
#include <string>
using namespace std;
class Matiere{
    private:
    string nom;
    double coef;
    vector<double> note;
    double moyenne;

    public:
    Matiere(string nom, double coef);
    ~Matiere();

    void setNom(string nom);
    void setCoef(double coef);
    void addNote(double note);

    double getMoyenne();
    string getNom();
};
#endif
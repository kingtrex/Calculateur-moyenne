#ifndef FONCTION_H
#define FONCTION_H
#include "header.h"
#include "Ue.h"
#include "Note.h"
#include "Matiere.h"
int recupUe(std::vector<Ue> &ue);
int recupMatiere(std::vector<Ue> &ue, std::vector<Matiere> &matiere);
int recupNote(std::vector<Matiere> &matiere);
void saveData(std::vector<Ue> ue, std::vector<Matiere> matiere);
double moyenneUe(std::vector<Matiere> &matiere, Ue &ue, std::vector<Ue> &ueTest);
void afficherMatiere(std::vector<Ue> &ue, std::vector<Matiere> &matiere, std::unordered_map<int, int> &mapMatiere, int action2);
void verifSaisie(int &var, int min = -2, int max = -2);
void verifSaisie(double &var, int min = -2, int max = -2);

#endif

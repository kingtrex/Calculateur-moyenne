
#include "Matiere.h"



void Matiere::setCoef(double coef){
    this->coef = coef;
}


void Matiere::getNote(){
    for(int i = 0; i < this->note.size(); i++){
        std::cout << "  " + note[i].getNom() + " " << note[i].getNote() << "/20 " << note[i].getPourcentage() << "%" << std::endl;
    }
}

void Matiere::saveNote(std::ofstream &file){
    for(int i = 0; i < this->note.size(); i++){
        file << this->getNom() << " " << this->note[i].getData() << std::endl;
    }
}

void Matiere::addNote(double note, double pourcentage, std::string label){
    this->note.push_back(Note(note, pourcentage, label));
    verifPourcentage();
}


int Matiere::getTotalPourcentage(){
    int totalPourcent = 0;
    for(int i = 0; i < note.size(); i++){
        totalPourcent += note[i].getPourcentage();
    }
    return totalPourcent;
}

void Matiere::verifPourcentage(){

    if(getTotalPourcentage() > 100){
        std::cout << "Erreur: total des \% supérieur à 100, Lancement de la réparation." << std::endl;
        reparNote();
    }
}
//réparer les notes si la somme des pourcentage est dupérieur a 100
void Matiere::reparNote(){
    do{
        std::cout << "Selectionner une note pour modifier le pourcentage:" << std::endl;
        getNote();
        int choix;
        std::cin >> choix;
        while(std::cin.fail() || choix < 0 || choix >= note.size()){
            std::cout << "Input invalid" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin >> choix;
        }
        std::cout << "Remplacer par quel pourcentage?" << std::endl;
        int choix2;
        std::cin >> choix2;
        while(std::cin.fail() || choix2 <= 0 || choix2 > 100){
            std::cout << "Input invalid" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin >> choix2;
        }
        note[choix].setPourcentage(choix2);
    }while(getTotalPourcentage() > 100);
}
//calculer la moyenne de la matère
double Matiere::calculMoyenne(){
    
    double totalNote = 0;

    for(int i = 0; i < note.size(); i++){
        totalNote += note[i].getNote() * note[i].getPourcentage();
    }
    this->setMoyenne((double)totalNote/100);
    return this->getMoyenne();
}
//calculer la moyenne de l'Ue
double Matiere::calculMoyenne(std::vector<Matiere> matiere, std::string nom){
    double num = 0;
    double denom = 0;

    for(int i = 0; i < matiere.size(); i++){
        if(matiere[i].getNom() == nom){
            num += calculMoyenne() * this->coef;
            denom += coef;
        }
    }
    this->setMoyenne(num/coef);
    return this->getMoyenne();
}
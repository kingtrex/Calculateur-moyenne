
#include "Matiere.h"



void Matiere::setCoef(double coef){
    this->coef = coef;
}

void Matiere::addNote(double note, double pourcentage, std::string label){
    this->note.push_back(Note(note, pourcentage, label));
    //calcul de la nouvelle moyenne
    this->moyenne = getMoyenne();
}

double Matiere::getMoyenne(){
    
    double totalNote = 0;

    for(int i = 0; i < note.size(); i++){
        totalNote += note[i].getNote() * note[i].getPourcentage();
    }
    return (double)totalNote/100;
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
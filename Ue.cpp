#ifndef UE_CPP
#define UE_CPP
#include "Ue.h"


std::vector<std::string> Ue::getMatiere(){
    std::vector<std::string> matiere;
    for(int i = 0; i < this->matiere.size(); i++){
        matiere.push_back(this->matiere[i].getNom());
    }
    return matiere;
}

int Ue::calculMoyenne(){
    double moyenne = 0;
    for(int i = 0; i < this->matiere.size(); i++){
        moyenne+=(this->matiere[i].getMoyenne() * this->matiere[i].getCoef());
    }
    return moyenne/this->matiere.size();
}



Ue::~Ue(){
    std::ofstream file;
    file.open(this->getNom() + "Matiere");
    if(file){
        for(int i = 0; i < this->matiere.size(); i++) file << this->matiere[i].getNom() << std::endl;
        file.close();
    }else{
        std::cout << "Erreur: impossible de sauvegarder les matière de l'UE \"" << this->getNom() << " " << std::endl;
        std::cin;
    }
}
#endif
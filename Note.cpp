#include "Note.h"

std::string Note::getData(){
    std::string data;
    data = this->getNom() + " " + std::to_string(this->getNote()) + " " + std::to_string(this->getPourcentage());
    return data;

}

void Note::modifNote(){
    std::cout << "Que voulez vous faire?" << std::endl;
    std::cout << "0: modifier le libelle" << std::endl;
    std::cout << "1: modifier la note" << std::endl;
    std::cout << "2: modifier le pourcentage" << std::endl;
    int action;
    std::cin >> action;
    this->verifSaisie(action, 0, 3);
    std::string nom;
    switch(action){
        case 0:
            std::cout << "Saisissez le nouveau nom" << std::endl;
            std::getline(std::cin >> std::ws, nom);
            this->setNom(nom);
            std::cout << "Libelle modifié" << std::endl;
            break;
        case 1:
            double note;
            std::cout << "Saisissez la nouvelle note" << std::endl;
            std::cin >> note;
            verifSaisie(note, 0, 21);
            this->setNote(note);
            std::cout << "Note modifiée avec succès" << std::endl;
            break;
        case 2:
            int pourcentage;
            std::cout << "Saisissez le nouveau pourcentage" << std::endl;
            std::cin >> pourcentage;
            this->verifSaisie(pourcentage, 0, 101);
            this->setPourcentage(pourcentage);
            std::cout << "Pourcentage modifier avec succes" << std::endl;
            break;
    }
}


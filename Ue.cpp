#include "Ue.h"

void Ue::verifNom(){
    std::string name = this->getNom();
    std::replace(name.begin(), name.end(), ' ', '_');
    this->setNom(name);
}


#include "Note.h"

std::string Note::getData(){
    std::string data;
    data = this->getNom() + " " + std::to_string(this->getNote()) + " " + std::to_string(this->getPourcentage());
    return data;

}
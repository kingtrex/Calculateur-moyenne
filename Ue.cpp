#include "Ue.h"

void Ue::verifNom(){
    std::string name = this->getNom();
    std::replace(name.begin(), name.end(), ' ', '_');
    this->setNom(name);
}

void Ue::setNom(std::string nom){
    this->nom = nom;
    //this->verifNom();
}

void Ue::verifSaisie(double &var, int min, int max){
    if(min == -2 && max == -2){
        while(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Input invalid" << std::endl;
            std::cin >> var;
        }    
    }else{
        while(std::cin.fail() || (var < min || var >= max)){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Input invalid" << std::endl;
            std::cin >> var;
        }
    }
}

void Ue::verifSaisie(int &var, int min, int max){
    if(min == -2 && max == -2){
        while(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Input invalid" << std::endl;
            std::cin >> var;
        }    
    }else{
        while(std::cin.fail() || (var < min || var >= max)){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Input invalid: min=" << min << " max= " << max  << std::endl;
            std::cin >> var;
        }
    }
}

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

void Matiere::addNote(double note, double pourcentage, const std::string &label){
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
        verifSaisie(choix, 0, 21);

        std::cout << "Remplacer par quel pourcentage?" << std::endl;
        int choix2;
        std::cin >> choix2;
        verifSaisie(choix2, 0, 101);

        note[choix].setPourcentage(choix2);
    }while(getTotalPourcentage() > 100);
}
//calculer la moyenne de la matère
void Matiere::calculMoyenne(){
    
    double totalNote = 0;

    for(int i = 0; i < note.size(); i++){
        totalNote += note[i].getNote() * note[i].getPourcentage();
    }
    this->setMoyenne((double)totalNote/100);
}
//calculer la moyenne de l'Ue
double Matiere::calculMoyenne(std::vector<Matiere> matiere, std::string nom){
    double num = 0;
    double denom = 0;

    for(int i = 0; i < matiere.size(); i++){
        if(matiere[i].getNom() == nom){
            num += matiere[i].getMoyenne() * this->coef;
            denom += coef;
        }
    }
    this->setMoyenne(num/coef);
    return this->getMoyenne();
}
/*afficher les notes
action = 0: afficher les notes sans les indices
action = 1: afficher les notes avec les indices
*/
void Matiere::afficheNote(int action = 0){
    switch(action){
        case 0:
            for(int i = 0; i < note.size(); i++){
                std::cout << note[i].getData() << std::endl;
            }
            break;
        case 1:
            for(int i = 0; i < note.size(); i++){
                std::cout << i << ": " << note[i].getData() << std::endl;
            }
            break;
    }
    
}

void Matiere::modifMatiere(int action){
    std::string libelle, nom;
    switch(action){
        case 2:
            std::cout << "Quel sera le libelle de la note?" << std::endl;
            std::getline(std::cin >> std::ws, libelle);
            double note, pourcentage;
            std::cout << "Quel note?" << std::endl;
            std::cin >> note;

            this->verifSaisie(note, 0, 21);

            std::cout << "Quel pourcentage de la note finale?" << std::endl;
            std::cin >> pourcentage;

            this->verifSaisie(pourcentage, 0, 101);
            this->addNote(note, pourcentage, libelle);
            break;
        case 3:
            std::cout << "Saisissez le nouveau nom: ";
            std::cin >> nom;
            this->setNom(nom);
            break;
        case 4:
            std::cout << "Saissez le nouveau coef: ";
            std::cin >> coef;
            this->verifSaisie(coef, 0, 101);

            this->setCoef(coef);
            break;
        case 5:
            std::cout << "Quelle note voulez-vous modifier?" << std::endl;
            this->afficheNote(1);
            int choix;
            std::cin >> choix;
            this->verifSaisie(choix, 0, this->getNbNote());
            this->note[choix].modifNote();
            break;
        case 6:
            std::cout << "Supprimer quelle note?" << std::endl;
            this->afficheNote(1);
            std::cin >> choix;
            this->verifSaisie(choix, 0, this->getNbNote());
            this->note.erase(this->note.begin()+choix);
            break;
        }
    this->calculMoyenne();
}

void Matiere::verifMoyenne(){
    if(this->getMoyenne() >= 10){
        std::cout << "Aucun rattrapage en théorie en " << this->getNom() <<std::endl;
    }else if(this->getTotalPourcentage() == 100 || this->noteIdeale()){
        std::cout << "Rattrapage probable en " << this->getNom() << std::endl;
    }
}

int Matiere::noteIdeale(){
    std::vector<Note> noteTest;
    //recuperer les notes existantes
    for(int i = 0; i < this->note.size(); i++){
        noteTest.push_back(Note(note[i].getNote(), note[i].getPourcentage(), note[i].getNom()));
    }    
    int pourcentageTest = 100 - this->getTotalPourcentage();
    noteTest.push_back(Note(10, pourcentageTest));
    if(this->calculMoyenne(noteTest) >= 10){
        std::cout << "il faudrait au moins 10 pour avoir une chance d'éviter le rattrapage" << std::endl;
        return 0;
    }
    for(double i = 10; i <= 20; i+=0.1){
        noteTest.back().setNote(i);
        if(this->calculMoyenne(noteTest) >= 10){
            std::cout << "il faudrait au moins " << i << " pour avoir une chance d'éviter le rattrapage" << std::endl;
            return 0;
        }
    }
    return 1;
}

double Matiere::calculMoyenne(std::vector <Note> note){
    double moyenne = 0;
    for(int i = 0; i < note.size(); i++){
        moyenne+=(note[i].getNote()*note[i].getPourcentage());
    }
    return moyenne;
}
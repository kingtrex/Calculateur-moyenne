#include "header.h"
#include "Ue.h"
#include "Matiere.h"

std::vector<Ue> recupUe(){
    std::vector<Ue> ue;
    std::ifstream recupUe;
    recupUe.open("fichierUe.txt");
    if(recupUe){
        std::string ligne;
        std::cout << "fichier ouvert" << std::endl;
        //récuperer les Ue
        while(getline(recupUe, ligne)){
            std::cout << "ajout de l'Ue " << ligne << std::endl; 
            ue.push_back(Ue(ligne));
        }
        recupUe.close();
        return ue;
    }
    
}

std::vector<Matiere> recupMatiere(std::vector<Ue> &ue){

    std::ifstream recupMatiere;
    recupMatiere.open("fichierMatiere.txt");
    if(recupMatiere){
        std::vector<Matiere> matiere;
        std::vector<std::string> data;
        std::string separateur = " ";
        std::string ligne;
        size_t pos = 0;
        //récupérer les matières
        while(getline(recupMatiere, ligne)){
            //obtenir les différentes données de la ligne
            while((pos = ligne.find(separateur)) != std::string::npos){
                data.push_back(ligne.substr(0, pos));
                ligne.erase(0, pos + separateur.size());
            }
            //trouver l'ID de l'Ue de la matière
            int indice;
            for(int i = 0; i < ue.size(); i++){
                if(ue[i].getNom() == data[0]){ 
                    indice = i; 
                    break;
                }
            }
            matiere.push_back(Matiere(data[1], std::stod(data[2]), ue[indice]));
        }
        recupMatiere.close();
        return matiere;
    }
}

void saveData(std::vector<Ue> ue, std::vector<Matiere> matiere){
    //sauvegarder les Ue pour la prochaine execution
    std::ofstream saveUe;
    saveUe.open("fichierUe.txt");
    for(int i = 0; i < ue.size(); i++){
        saveUe << ue[i].getNom() << std::endl;
    }
    saveUe.close();
    //sauvegarder les matière pour la prochaine execution
    std::ofstream saveMatiere;
    saveMatiere.open("fichierMatiere.txt");
    for(int i = 0; i < matiere.size(); i++){
        saveMatiere << matiere[i].getUe() << " " << matiere[i].getNom() << " " << matiere[i].getCoef() << " " << std::endl;
    }
    saveMatiere.close();

    //sauvegarde des notes pour la prochaine execution
    std::ofstream saveNote;
    saveNote.open("fichierNote.txt");
    for(int i = 0; i < matiere.size(); i++){
        matiere[i].saveNote(saveNote);
    }
}

<<<<<<< Updated upstream
=======
double moyenneUe(std::vector<Matiere> &matiere, Ue &ue){
    double num = 0;
    double denom = 0;

    for(int i = 0; i < matiere.size(); i++){
        if(matiere[i].getUe() == ue.getNom()){
            num += (matiere[i].getMoyenne() * matiere[i].getCoef());
            denom += matiere[i].getCoef();
        }
    }
    return num/denom;
}

>>>>>>> Stashed changes
int main()
{

    //récupérer les Ue de la dernière execution
    std::vector<Ue> ue = recupUe();
    //récupérér les matières de la dernère execution
    std::vector<Matiere> matiere = recupMatiere(ue);

    int action;
    std::string nom;
    do{
        
        std::cout << "Que voulez vous faire?" << std::endl;
        std::cout << "1: voir les UE et les matières" << std::endl;
        std::cout << "2: ajouter un nouvel UE" << std::endl;
        std::cout << "3: modifier un UE" << std::endl;
        //inserez de nouvelles options ici
        std::cout << "0: sauvegarder et quitter" << std::endl;

        std::cin >> action;
        if(action == 1 | action == 3 && ue.size() == 0){
            std::cout << "Aucun UE enregistré." << std::endl;
            continue;
        }
        std::string nom;
        
        while(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Input invalid" << std::endl;
            std::cin >> action;
        }

        switch(action){
            //Afficher les Ue
            case 1:
                //Afficher tout les Ue
                for(int i = 0; i < ue.size() ; i++){
                    std::cout << "Ue: " << ue[i].getNom() << std::endl;
                    for(int j = 0; j < matiere.size(); j++){
                        //afficher les matière de l'Ue
                        std::cout << "afficher matieres" << std::endl;
                        if(matiere[j].getUe() == ue[i].getNom()){ 
                            std::cout << " " << matiere[j].getNom() << " Coef: " << matiere[j].getCoef() << std::endl;
                            //afficher les notes de cet Ue
                            matiere[j].getNote();
                        }

                    }
                }
                break;
            //enregistrer un nouvel Ue
            case 2:
                std::cout << "Saisissez un nom: ";
                std::getline(std::cin >> std::ws, nom);
                ue.push_back(Ue(nom));
                break;
            //modifier un Ue
            case 3:
                int action2;
                std::cout << "Quel Ue voulez vous modifier?" << std::endl;
                std::cout << "-1: retour" << std::endl;
                //Afficher les Ue
                for(int i = 0; i < ue.size(); i++){
                        std::cout << i << ": " + ue[i].getNom() << std::endl;
                }
                std::cin >> action2;

                //gestion des erreurs
                while(std::cin.fail() || (action2 < -1 || action2 >= ue.size())){
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Input invalid" << std::endl;
                    std::cin >> action2;
                }


                int action3;
                do{
                    std::cout << "Que voulez-vous faire?" << std::endl;
                    std::cout << "0: retour" << std::endl;
                    std::cout << "1: ajouter une matiere" << std::endl;
                    std::cout << "2: ajouter une note" << std::endl;
                }while(!(std::cin >> action3));
                
                std::string nomMatiere;

                switch(action3){
                    
                    //ajouter une matière
                    case 1:
                        std::cout << "Comment voulez-vous appeler cette matière?" << std::endl;
                        
                        std::cin >> nomMatiere;
                        std::cout << "Quel sera son coef?" << std::endl;
                        double coef;
                        std::cin >> coef;

                        matiere.push_back(Matiere(nomMatiere, coef, ue[action2]));
                        std::cout << "retour au menu principal" << std::endl;

                    case 2:
                        std::cout << "Ajouter une note a quel matiere?" << std::endl;
                        for(int i = 0; i < matiere.size(); i++){
                            std::cout << i << " Ue: " + matiere[i].getUe() << " Matiere: " << matiere[i].getNom() << std::endl;
                        }
                        int choixMatiere;
                        std::cin >> choixMatiere;
                        if(!(choixMatiere < 0 || choixMatiere >= matiere.size())){
                            std::string libelle;
                            std::cout << "Quel sera le libelle de la note?" << std::endl;
                            std::cin >> libelle;
                            double note, pourcentage;
                            std::cout << "Quel note?" << std::endl;
                            std::cin >> note;
                            std::cout << "Quel pourcentage de la note finale?" << std::endl;
                            std::cin >> pourcentage;

                            matiere[choixMatiere].addNote(note, pourcentage, libelle);
                        }else std::cout << "Erreur: matiere introuvable, retour au menu principal" <<std::endl;
                        break;
                }

            break;
            //ajouter les case ici
        }
    }while(action != 0);

    saveData(ue, matiere);

    return 0;
}

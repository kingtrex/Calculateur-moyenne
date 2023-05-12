#include "header.h"
#include "Ue.h"
#include "Matiere.h"
#include "fonction.h"

const int RETOUR = -1;
//récupérer les Ue de la dernière execution


int main(){

    std::vector<Ue> ue;
    if(recupUe(ue)){
        std::cout << "Impossible de lire les Ue" << std::endl; 
        return 1;
    }
    std::vector<Matiere> matiere;
    if(recupMatiere(ue, matiere)){
        std::cout << "Impossible de lire les matière" << std::endl;
        return 1;
    }

    if(recupNote(matiere)){
        std::cout << "Impossible de lire les notes" << std::endl;
        return 1;
    }
    //calculer la moyenne des matières
    for(int i = 0; i < matiere.size(); i++) matiere[i].calculMoyenne();
    
    int action;
    std::string nom;
    do{
        
        std::cout << "Que voulez vous faire?" << std::endl;
        std::cout << "1: voir les UE et les matieres" << std::endl;
        std::cout << "2: ajouter un nouvel UE" << std::endl;
        std::cout << "3: modifier un UE" << std::endl;
        //inserez de nouvelles options ici
        std::cout << "0: sauvegarder et quitter" << std::endl;

        std::cin >> action;
        //changer le 3ème paramètres si on ajoute des fonctionnalités
        verifSaisie(action, 0, 4);
        if((action == 1 || action == 3) && ue.size() == 0){
            std::cout << "Aucun UE enregistre." << std::endl;
            continue;
        }
        std::string nom;

        switch(action){
            //Afficher les Ue
            case 1:
                //Afficher tout les Ue
                for(int i = 0; i < ue.size() ; i++){
                    std::cout << "Ue: " << ue[i].getNom() << std::endl;
                    std::cout << "Moyenne: " << moyenneUe(matiere, ue[i], ue) << std::endl;
                    for(int j = 0; j < matiere.size(); j++){
                        //afficher les matière de l'Ue
                        if(matiere[j].getUe() == ue[i].getNom()){ 
                            std::cout << " " << matiere[j].getNom() << " Coef: " << matiere[j].getCoef() << " Moyenne: " << matiere[j].getMoyenne() << std::endl;
                            //afficher les notes de cet Ue
                            matiere[j].getNote();
                            if(moyenneUe(matiere, ue[i], ue) < 10 && matiere[j].getMoyenne() < 10){
                                matiere[j].verifMoyenne();
                            }
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
                verifSaisie(action2, -1, ue.size());
                if(action2 == -1) break;

                int action3;

                std::cout << "Que voulez-vous faire?" << std::endl;
                std::cout << "0: retour" << std::endl;
                std::cout << "1: ajouter une matiere" << std::endl;
                std::cout << "2: ajouter une note" << std::endl;
                std::cout << "3: changer le nom d'une matiere" << std::endl;
                std::cout << "4: changer le coef d'une matiere" << std::endl;
                std::cout << "5: changer une note" << std::endl;
                std::cout << "6: supprimer une note" << std::endl;
                std::cin >> action3;
                //changer le 3ème paramètres si on ajoute des fonctionnalités
                verifSaisie(action3, 0, 7);

                std::string nom;
                std::unordered_map<int, int> mapMatiere;
                double coef;
                int choixMatiere;
                switch(action3){
                    
                    //ajouter une matière
                    case 1:
                        std::cout << "Comment voulez-vous appeler cette matiere?" << std::endl;
                        //consider les espaces comme inclus dans la saisie
                        std::getline(std::cin >> std::ws, nom);

                        std::cout << "Quel sera son coef?" << std::endl;
                        std::cin >> coef;
                        verifSaisie(coef);

                        matiere.push_back(Matiere(nom, coef, ue[action2]));
                        std::cout << "retour au menu principal" << std::endl;
                        break;

                    
                    case 2: case 3: case 4: case 5: case 6:
                        std::cout << "Quel matiere voulez-vous modifier?" << std::endl;
                        afficherMatiere(ue, matiere, mapMatiere, action2);
                        std::cin >> choixMatiere;
                        verifSaisie(choixMatiere, 0, mapMatiere.size());
                        matiere[mapMatiere[choixMatiere]].modifMatiere(action3);
                        break;
                    default:
                        std::cout << "Fonction inexistante " << std::endl;
                        break;
                }

            break;
            //ajouter les case ici
        }
    }while(action != 0);

    saveData(ue, matiere);

    return 0;
}

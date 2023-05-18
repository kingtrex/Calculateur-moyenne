/****************************************************************************************************
 *                                    Projet: calculateur de moyenne                                *
 *                                    Auteur: Thibault TANNÉ                                        *
 *                                          18/05/2023                                              *
*****************************************************************************************************/
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
                modifUe(ue, matiere);
                break;
            //ajouter les case ici
        }
    }while(action != 0);

    saveData(ue, matiere);

    return 0;
}

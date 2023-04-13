#include "header.h"
#include "Ue.h"
#include "Matiere.h"
int main()
{

    std::string ligne;
    std::vector<Ue> ue;
    std::vector<Matiere> matiere;
    //récupérer les Ue de la dernière execution
    std::ifstream recupUe;
    recupUe.open("fichierUe.txt");
    if(recupUe){
        std::cout << "fichier ouvert" << std::endl;
        std::vector<std::string> data;
        //récuperer les Ue
        while(getline(recupUe, ligne)){

            ue.push_back(Ue(ligne));
        }
        recupUe.close();
    }

    int action;
    std::string nom;
    do{
        
        std::cout << "Que voulez vous faire?" << std::endl;
        std::cout << "1: voir les UE et les matières" << std::endl;
        std::cout << "2: ajouter un nouvel UE" << std::endl;
        std::cout << "3: modifier un UE" << std::endl;

        std::cout << "0: sauvegarder et quitter" << std::endl;

        std::cin >> action;
        if(action == 1 | action == 3 && ue.size() == 0){
            std::cout << "Aucun UE enregistré." << std::endl;
            continue;
        }
        switch(action){
            //Afficher les Ue
            case 1:
                //Afficher tout les Ue
                for(int i = 0; i < ue.size() ; i++){
                    std::cout << "Ue: " << ue[i].getNom() << std::endl;
                    for(int j = 0; j < matiere.size(); j++){
                        if(matiere[j].getUe() == ue[i].getNom()) std::cout << matiere[j].getNom() << std::endl;
                    }
                }
                break;
            //enregistrer un nouvel Ue
            case 2:
                std::cout << "Saisissez un nom: ";
                std::cin >> nom;
                ue.push_back(Ue(nom));
                break;
            //modifier un Ue
            case 3:
                int action2;
                std::cout << "Quel Ue voulez vous modifier?" << std::endl;
                //Afficher les Ue
                for(int i = 0; i < ue.size(); i++){
                    std::cout << i << ": " + ue[i].getNom() << std::endl;
                }

                std::cin >> action2;
                
                if(action2 < 0 || action2 >= ue.size()){
                    std::cout << "Erreur: Ue non-reconnu, retour au menu principal" << std::endl;
                    break;
                }

                int action3;
                std::cout << "Que voulez-vous faire?" << std::endl;
                std::cout << "0: retour" << std::endl;
                std::cout << "1: ajouter une matiere" << std::endl;

                std::cin >> action3;
                switch(action3){
                    case 1:
                        std::string nomMatiere;
                        double coef;
                        std::cout << "Comment voulez-vous appeler cette matière?" << std::endl;
                        std::cin >> nomMatiere;
                        std::cout << "Quel sera son coef?" << std::endl;
                        std::cin >> coef;

                        matiere.push_back(Matiere(nomMatiere, coef, ue[action2]));
                        std::cout << "retour au menu principal" << std::endl;
                }



                
                

            break;

        }

    }while(action != 0);

    //sauvegarder les Ue pour la prochaine execution
    std::ofstream saveUe;
    saveUe.open("fichierUe.txt");
    for(int i = 0; i < ue.size(); i++){
        saveUe << ue[i].getNom() << std::endl;
    }
    saveUe.close();
    return 0;
}

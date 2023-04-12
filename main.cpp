#include "header.h"
#include "Ue.h"
int main()
{

    std::string ligne;
    std::vector<Ue> ue;
    std::unordered_multimap<std::string, std::string> matiere, note;
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
                std::cout << "Quel Ue voulez vous modifier?" << std::endl;
                //afficher les Ue
                for(int i = 0; i < ue.size(); i++){
                    std::cout << i << ": " + ue[i].getNom() << std::endl;
                }
                int action2;

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

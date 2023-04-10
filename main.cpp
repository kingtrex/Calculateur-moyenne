#include "header.h"

int main()
{

    std::string ligne;
    std::vector<Ue> ue;
    std::ifstream fileUe;
    fileUe.open("fichierUe.txt");
    if(fileUe){
        std::vector<std::string> data;
        //récuperer les Ue
        while(getline(fileUe, ligne)){
            ue.push_back(Ue(ligne));
        }
        fileUe.close();
    }

    std::cout << "Que voulez vous faire?" << std::endl;
    std::cout << "1: voir les UE et les matières" << std::endl;
    std::cout << "2: ajouter un nouvel UE" << std::endl;
    std::cout << "3: modifier un UE" << std::endl;

    int action;
    std::cin >> action;
    switch(action){
        case 1:
            if(ue.size() == 0){
                std::cout << "Aucun UE enregistré." << std::endl;
                break;
            }
            //for(int i = 0; i < ue.size() ; i++) 

    }

    std::ifstream file;
    
    return 0;
}

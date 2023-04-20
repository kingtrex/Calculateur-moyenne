#include "header.h"
#include "Ue.h"
#include "Matiere.h"
const int RETOUR = -1;
//récupérer les Ue de la dernière execution
std::vector<Ue> recupUe(){
    std::vector<Ue> ue;
    std::ifstream recupUe;
    recupUe.open("fichierUe.txt");
    if(recupUe){
        std::string ligne;
        //récuperer les Ue
        while(getline(recupUe, ligne)){
            ue.push_back(Ue(ligne));
        }
        recupUe.close();
        return ue;
    }
    
}
//récupérer les matières de la dernère execution
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
            data.clear();
        }
        recupMatiere.close();
        return matiere;
    }
}
//récupérer les notes de la dernière execution
void recupNote(std::vector<Matiere> &matiere){
    std::ifstream file;
    file.open("fichierNote.txt");
    std::string ligne;
    std::string separateur = " ";
    std::vector<std::string> data;
    size_t pos = 0;
    while(getline(file, ligne)){
        //récuperer les données de chaque ligne
        while((pos = ligne.find(separateur)) != std::string::npos){
            data.push_back(ligne.substr(0, pos));
            ligne.erase(0, pos + separateur.size());
        }
        data.push_back(ligne);
        for(int i = 0; i < matiere.size(); i++){
            if(data[0] == matiere[i].getNom()) matiere[i].addNote(std::stod(data[2]), std::stod(data[3]), data[1]);
        }
        data.clear();
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

double moyenneUe(std::vector<Matiere> &matiere, Ue &ue, std::vector<Ue> &ueTest){
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

void afficherMatiere(std::vector<Ue> &ue, std::vector<Matiere> &matiere, std::unordered_map<int, int> &mapMatiere, int action2){
    for(int i = 0, j = 0; i < matiere.size(); i++){
        if(matiere[i].getUe() == ue[action2].getNom()){
            mapMatiere.emplace(j, i);
            std::cout << j << ": " << matiere[i].getNom() << std::endl;
            j++;
        }
    }
}
/*verifier les saisie: 
    var: la variable a tester, continue si
    min: si var >= min
    max: si var < max
    Nota, si min et max non données, verifie juste si la saisie est un entier
*/
void verifSaisie(auto &var, int min = -2, int max = -2){
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

int main(){

    std::vector<Ue> ue = recupUe();
    std::vector<Matiere> matiere = recupMatiere(ue);
    recupNote(matiere);
    //calculer la moyenne des matières
    for(int i = 0; i < matiere.size(); i++){
        matiere[i].calculMoyenne();
    }
    
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
        verifSaisie(action, 0, 4);
        //action = 1;
        if(action == 1 | action == 3 && ue.size() == 0){
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
                            std::cout << " " << matiere[j].getNom() << " Coef: " << matiere[j].getCoef() << " Moyenne: " << matiere[j].calculMoyenne() << std::endl;
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
                std::cout << matiere[0].getUe() << std::endl;
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
                std::cin >> action3;
                verifSaisie(action3, 0, 6);

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

                    /*case 2:
                        std::cout << "Ajouter une note a quel matiere?" << std::endl;
                        
                        afficherMatiere(ue, matiere, mapMatiere, action2);

                        
                        std::cin >> choixMatiere;
                        verifSaisie(choixMatiere);

                        if(!(choixMatiere < 0 || choixMatiere >= mapMatiere.size())){
                            std::string libelle;
                            std::cout << "Quel sera le libelle de la note?" << std::endl;
                            std::getline(std::cin >> std::ws, libelle);
                            double note, pourcentage;
                            std::cout << "Quel note?" << std::endl;
                            std::cin >> note;

                            verifSaisie(note);

                            std::cout << "Quel pourcentage de la note finale?" << std::endl;
                            std::cin >> pourcentage;

                            verifSaisie(pourcentage);

                            matiere[mapMatiere[choixMatiere]].addNote(note, pourcentage, libelle);
                        }else std::cout << "Erreur: matiere introuvable, retour au menu principal" <<std::endl;
                        break;

                    case 3:
                        std::cout << "Saisissez le nouveau nom: ";
                        std::cin >> nom;
                        ue[action2].setNom(nom);
                        break;
                    
                    case 4:
                        std::cout << "Quelle matiere voulez-vous modifier:" << std::endl;

                        afficherMatiere(ue, matiere, mapMatiere, action2);
                        
                        std::cin >> choixMatiere;
                        verifSaisie(choixMatiere, 0, mapMatiere.size());

                        std::cout << "Saissez le nouveau coef: ";
                        std::cin >> coef;
                        verifSaisie(coef);

                        matiere[mapMatiere[choixMatiere]].setCoef(coef);

                    case 5:
                        std::cout << "Modifier une note de quel matiere?" << std::endl;
                        afficherMatiere(ue, matiere, mapMatiere, action2);
                        /*for(int i = 0; i < matiere.size(); i++){
                            //std::cout << ue[action2].getNom() << " " << matiere[i].getUe() << std::endl;
                            if(ue[action2].getNom() == matiere[i].getUe()){
                                std::cout << i << ": " + matiere[i].getNom() << std::endl;
                            }
                        }*/
                        /*int choixNote;
                        std::cin >> choixNote;
                        verifSaisie(choixNote);

                        std::cout << "Que voulez-vous faire?";
                        std::cin >> choixMatiere;
                        verifSaisie(choixMatiere, -1, mapMatiere.size());
                        
                        std::cout << "Que voulez-vous modifier?" << std::endl;
                        std::cout << "-1: retour" << std::endl;
                        std::cout << "0: modifier la note" << std::endl;
                        std::cout << "1: modifier le pourcentage" << std::endl;
                        std::cout << "2: modifier le libelle" << std::endl;

                        int choixNote;
                        std::cin >> choixNote;
                        verifSaisie(choixNote, RETOUR, 3);
                        switch(choixNote){
                            case -1:
                                break;
                            case 0:
                                matiere[mapMatiere[choixMatiere]].modifNote()
                        }
                        break;
                    */
                    case 2: case 3: case 4: case 5:
                        std::cout << "Quel matiere voulez-vous modifier?" << std::endl;
                        afficherMatiere(ue, matiere, mapMatiere, action2);
                        std::cin >> choixMatiere;
                        verifSaisie(choixMatiere, 0, mapMatiere.size());
                        matiere[mapMatiere[choixMatiere]].modifMatiere(action3);
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

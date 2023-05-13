#include "fonction.h"
int recupUe(std::vector <Ue> &ue){
    std::ifstream recupUe;
    recupUe.open("fichierUe.txt");
    if(recupUe){
        std::string ligne;
        //récuperer les Ue
        while(getline(recupUe, ligne)){
            ue.push_back(Ue(ligne));
        }
        recupUe.close();
        std::cout << "Ue dans fonction: " << ue.size() << std::endl;

        return 0;
    }
    return 1;
    
}
//récupérer les matières de la dernère execution
int recupMatiere(std::vector<Ue> &ue, std::vector<Matiere> &matiere){

    std::ifstream recupMatiere;
    recupMatiere.open("fichierMatiere.txt");
    if(recupMatiere){
        
        std::vector<std::string> data;
        std::string separateur = " ";
        std::string ligne;
        size_t pos = 0;
        //récupérer les matières
        while(getline(recupMatiere, ligne)){
            std::cout << ligne << std::endl;
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
            std::cout << data[1] << " " << data[2] << " " << ue[indice].getNom() << std::endl;
            std::cout << "adresse:" << &ue[indice] << std::endl;
            matiere.push_back(Matiere(data[1], std::stod(data[2]), ue[indice]));

            data.clear();
        }
        std::cout << "matiere dans fonction: " << matiere.size() << std::endl;
        recupMatiere.close();
        std::cout << "matiere dans fonction: " << matiere.size() << std::endl;
        return 0;
    }
    return 1;
}
//récupérer les notes de la dernière execution
int recupNote(std::vector<Matiere> &matiere){
    std::ifstream file;
    file.open("fichierNote.txt");
    if(file){
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
        return 0;
    }
    return 1;
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

        if(matiere[i].getUe() == ue.getNom() && matiere[i].getNbNote() != 0){
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
void verifSaisie(int &var, int min, int max){
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

void verifSaisie(double &var, int min, int max){
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
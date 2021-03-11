#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Being {

public:
    string name;
    Being(){
        health = 0;
        strength = 0;
        intelligence = 0;
    }
    Being(string name, int health, int strength, int intelligence){
        this->name = name;
        this->health = health;
        this->strength = strength;
        this->intelligence = intelligence;
    };
    virtual void print_information() = 0;
protected:
    
    int health;
    int strength;
    int intelligence;
};

class Person : public Being {

public:
    Person() : Being(){
        
    }
    Person(string name, string role, string gender, int health, int strength, int intelligence, int fear) : Being(name, health,strength,intelligence){
        this->gender = gender;
        this->fear = fear;
        this->name = name;
        this->role = role;
    }
    virtual void print_information(){
        cout << "\nPerson" << endl;
        cout << "name: " << name << endl;
        cout << "role: " << role << endl;
        cout << "Health: " << health << endl;
        cout << "Strength: " << strength << endl;
        cout << "Intelligence: " << intelligence << endl;
        cout << "Gender: " << gender << endl;
        cout << "Fear: " << fear << endl;
    }
protected:
    string gender;
    string name;
    string role;
    int fear;
};
class Investigator : public Person{
public:
    Investigator(): Person(){

    }
    Investigator(string name, string role, string gender, int health, int strength, int intelligence, int fear, int terror) 
        : Person(name, role, gender, health, strength, intelligence, fear){
            this->terror = terror;
    }
    virtual void print_information(){
        cout << "\nInvestigator" << endl;
        cout << "name: " << name << endl;
        cout << "role: " << role << endl;
        cout << "Health: " << health << endl;
        cout << "Strength: " << strength << endl;
        cout << "Intelligence: " << intelligence << endl;
        cout << "Gender: " << gender << endl;
        cout << "Fear: " << fear << endl;
    }
private:
    int terror;
};

class Creature : public Being {
public:
    Creature() : Being(){
        
    }
    Creature(string name, string species, int health, int strength, int intelligence, bool natural, int disquiet) : Being(name, health,strength,intelligence){
        this->natural = natural;
        this->disquiet = disquiet;
        this->name = name;
        this->species = species;
    }
    virtual void print_information(){
        cout << "\nCreature" << endl;
        cout << "Name: " << name << endl;
        cout << "Species: " << species << endl;
        cout << "Health: " << health << endl;
        cout << "Strength: " << strength << endl;
        cout << "Intelligence: " << intelligence << endl;
        if (natural == 1){
            cout << "Natural" << endl;
        }
        else if (natural == 0){
            cout << "Unnatural" << endl;
        }
        cout << "Natural: " << natural << endl;
        cout << "Disquiet: " << disquiet << endl;
    }
protected:
    string name;
    string species;
    bool natural;
    int disquiet;

};
class Eldritch : public Creature{
public: 
    Eldritch() : Creature(){

    }
    Eldritch(string name,string species, int health, int strength, int intelligence,bool natural, int disquiet, int traumatism) : Creature(name,species, health, strength, intelligence, natural, disquiet){
        this->traumatism = traumatism;
    }
    virtual void print_information(){
        cout << "\nEldritch Horror" << endl;
        cout << "Name: " << name << endl;
        cout << "Species: " << species << endl;
        cout << "Health: " << health << endl;
        cout << "Strength: " << strength << endl;
        cout << "Intelligence: " << intelligence << endl;
        cout << "Unnatural" << endl;
        cout << "Disquiet: " << disquiet << endl;
        cout << "Traumatism: " << traumatism << endl;
    }
private:
    int traumatism;
};


class Species{
public:
    string name;
    int health;
    int strength;
    int intelligence;
    bool natural;
    int disquiet;
    int count;
    int traumatism;
    string type;

    Species(){
        this->count = 0;
    }
    Species(string name, string type, int health, int strength, int intelligence, bool natural, int disquiet, int traumatism){
        this->name = name;
        this->type = type;
        this->health = health;
        this->strength = strength;
        this->intelligence = intelligence;
        this->natural = natural;
        this->disquiet = disquiet;
        this->traumatism = traumatism;
    }
    virtual void print_information(){
        cout << "Species: " << name << endl;
        if (traumatism < 4){
            cout << "Eldritch Horror" << endl;
        }
        else {
            cout << "Creature" << endl;

        }
        cout << "Health: " << health << endl;
        cout << "Strength: " << strength << endl;
        cout << "Intelligence: " << intelligence << endl;
        if (natural == 0){
            cout << "Unnatural" << endl;
        }
        else if (natural == 1){
            cout << "Natural" << endl;
        }
        cout << "Disquiet: " << disquiet << endl;
        if (traumatism < 4){
            cout << "Traumatism: " << traumatism << endl;
        }
    }

};
class Role{
public:
    string name;
    int minH;
    int maxH;
    int minS;
    int maxS;
    int minI;
    int maxI;

    Role(){

    }
    Role(string name, int minH,int maxH, int minS, int maxS, int minI, int maxI){
        this->name = name;
        this->minH = minH;
        this->maxH = maxH;
        this->minS = minS;
        this->maxS = maxS;
        this->minI = minI;
        this->maxI = maxI;
    }
    virtual void print_information(){
        cout << "Person" << endl;
        cout << "Role: " << name << endl;
        cout << "Health: " << minH << "-" << maxH << endl;
        cout << "Strength: " << minS << "-" << maxS << endl;
        cout << "Intelligence: " << minI << "-" << maxI << endl;
    }

};


void create_role(vector<Role *> &roles, vector<string> &rolenames);
void create_species(vector<Species *> &species, vector<string> &speciesnames, bool isEldrich);
void view_roles(vector<string> rolenames);
void view_species(vector<string> speciesnames);
void show_menu();
void read_data(vector<Role *> &roles, vector<Species *> &species, vector<string> &rolenames, vector<string> &speciesnames);
void view_beings(vector<Being *> beings);
void deleteRole(vector<Role *> &roles, int at);
void deleteSpecie(vector<Species *> &species, int at);

int main() {
    srand(time(NULL));

    vector<Species *> species;
    vector<Role *> roles;
    vector<Being *> beings;
    vector<string> rolenames;
    vector<string> speciesnames;
    int selection;
    int choice = 0;
    int displayChoice = 0;
    bool back = false;
    bool quit = false;
    enum Main {
        CREATE = 1,
        DISPLAY = 2,
        QUIT = 3
    };
    enum Choice {
        PERSON = 1, 
        INVESTIGATOR = 2, 
        CREATURE = 3,
        ELDRITCH = 4,
        BACK = 5
    };
    enum DisplayChoice {
        ROLES = 1,
        SPECIES = 2,
        INDIVIDUALS = 3,
        dBACK = 4
    };

    string name;
    string gender;
    
    read_data(roles, species, rolenames, speciesnames);
    while (quit == 0)
    {
        system("clear");
        show_menu();
        cin >> selection;
        switch (selection)
        {
        case CREATE:
            system("clear");    
            cout << "1. Person" << endl;
            cout << "2. Investigator" << endl;
            cout << "3. Creature" << endl;
            cout << "4. Eldritch horror" << endl;
            cout << "5. Go back" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            back = 0;
            while(back == 0){

            
                switch (choice)
                {
                case PERSON:
                    system("clear");
                    if(rolenames.size() == 0)
                    {
                        create_role(roles,rolenames);
                    }

                    
                    cout << "Select Role: " << endl;
                    view_roles(rolenames);
                    cout << rolenames.size() + 1  << ". to create new Role: " << endl;
                    cout << "Enter your choice: ";
                    int pickRole;
                    cin >> pickRole;
                    
                    if (pickRole == rolenames.size() + 1){
                        create_role(roles, rolenames);
                    }
                    else {
                        system("clear");
                        cout << "Create person with role: " << rolenames.at(pickRole-1) << endl;
                        cout << "Enter Name: ";
                        cin >> name;
                        cout << "Enter Gender: ";
                        cin >> gender;
                    
                    
                    //Person(name, role, gender, health, strength, intelligence, fear)
                        beings.push_back(new Person(name, rolenames.at(pickRole-1), gender,
                            rand() % (roles.at(pickRole-1)->maxH - roles.at(pickRole-1)->minH+1) + roles.at(pickRole-1)->minH, 
                            rand() % (roles.at(pickRole-1)->maxS - roles.at(pickRole-1)->minS+1) + roles.at(pickRole-1)->minS,
                            rand() % (roles.at(pickRole-1)->maxI - roles.at(pickRole-1)->minI+1) + roles.at(pickRole-1)->minI,
                            rand() % (10 - 0+1) + 0));
                            system("clear");
                        back = 1;
                    }
                    break;
                case CREATURE:
                    back = 0;
                    system("clear");
                    if(speciesnames.size() == 0)
                    {
                        create_species(species,speciesnames, false);
                    }

                    cout << "Select species" << endl;
                    
                    view_species(speciesnames);
                    cout << speciesnames.size() + 1 << ". " << "Create new species" << endl;
                    cout << "Enter your choice: ";
                    int pickSpecies;
                    cin >> pickSpecies;
                    if (pickSpecies == speciesnames.size() + 1){
                        create_species(species, speciesnames, false);
                    }
                    else {
                        system("clear");
                        cout << "Created new " << speciesnames.at(pickSpecies-1) << endl;
                        species.at(pickSpecies-1)->count++;
                        name = speciesnames.at(pickSpecies-1) + " " + to_string(species.at(pickSpecies-1)->count);
                        beings.push_back(new Creature(name, speciesnames.at(pickSpecies-1), species.at(pickSpecies-1)->health, species.at(pickSpecies-1)->strength,species.at(pickSpecies-1)->intelligence,species.at(pickSpecies-1)->natural,species.at(pickSpecies-1)->disquiet));
                        system("pause");
                        back = 1;
                        
                    }
                    break;
                case INVESTIGATOR:
                    back = 0;
                    system("clear");
                    if(rolenames.size() == 0)
                    {
                        create_role(roles,rolenames);
                    }
                    cout << "Select Role: " << endl;
                    view_roles(rolenames);
                    cout << rolenames.size() + 1  << ". to create new Role: " << endl;
                    cout << "Enter your choice: ";
                    int pickInv;
                    cin >> pickInv;
                    
                    if (pickInv == rolenames.size() + 1){
                        create_role(roles, rolenames);
                    }
                    else {
                        system("clear");
                        cout << "Create investigator with role: " << rolenames.at(pickInv-1) << endl;
                        cout << "Enter Name: ";
                        cin >> name;
                        cout << "Enter Gender: ";
                        cin >> gender;
                    
                    
                    //Person(name, role, gender, health, strength, intelligence, fear)
                        beings.push_back(new Investigator(name, rolenames.at(pickInv-1), gender,
                            rand() % (roles.at(pickInv-1)->maxH - roles.at(pickInv-1)->minH+1) + roles.at(pickInv-1)->minH, 
                            rand() % (roles.at(pickInv-1)->maxS - roles.at(pickInv-1)->minS+1) + roles.at(pickInv-1)->minS,
                            rand() % (roles.at(pickInv-1)->maxI - roles.at(pickInv-1)->minI+1) + roles.at(pickInv-1)->minI,
                            rand() % (10 - 0+1) + 0, rand() % (3 - 0+1) + 0));
                        back = 1;
                        system("clear");
                    }
                    
                    back = 1;
                    break;
                case ELDRITCH:
                    system("clear");
                    if(speciesnames.size() == 0)
                    {
                        create_species(species,speciesnames, false);
                    }

                    cout << "Select species" << endl;
                    
                    view_species(speciesnames);
                    cout << speciesnames.size() + 1 << ". " << "Create new species" << endl;
                    cout << "Enter your choice: ";
                    int pickEld;
                    cin >> pickEld;
                    if (pickEld == speciesnames.size() + 1){
                        create_species(species, speciesnames, false);
                    }
                    else {
                        system("clear");
                        cout << "Created new " << speciesnames.at(pickEld-1) << endl;
                        species.at(pickEld-1)->count++;
                        name = speciesnames.at(pickEld-1) + " " + to_string(species.at(pickEld-1)->count);
                        // Eldritch(string name,string species, int health, int strength, int intelligence,bool natural, int disquiet, int traumatism) 
                        beings.push_back(new Eldritch(name, speciesnames.at(pickEld-1), species.at(pickEld-1)->health, species.at(pickEld-1)->strength, species.at(pickEld-1)->intelligence, 0, 10, species.at(pickEld-1)->traumatism));
                        system("pause");
                        back = 1;
                    }
                    back = 1;
                    break;
                case BACK:
                    back = 1;
                    break;

                default:
                    back = 1;
                    break;
                } 
            }
            break;
        case DISPLAY:
            system("clear");
            cout << "1. Roles" << endl;
            cout << "2. Species" << endl;
            cout << "3. Individuals" << endl;
            cout << "4. Back" << endl;
            cout << "Enter your choice: ";
            cin >> displayChoice;
            switch (displayChoice){
                case ROLES:
                    system("clear");
                    int roleViewChoice;
                    int roleDelChoice;
                    view_roles(rolenames);
                    cin >> roleViewChoice;
                    system("clear");
                    roles.at(roleViewChoice-1)->print_information();
                    cout << "1. Delete 2.Back" << endl;
                    cout << "Enter your choice: ";
                    cin >> roleDelChoice;
                    if (roleDelChoice == 1){
                        rolenames.erase(rolenames.begin() +  roleViewChoice-1);
                        deleteRole(roles, roleViewChoice);
                        read_data(roles, species, rolenames, speciesnames);
                        system("clear");
                    }
                    else{
                        break;
                    }
                    
                    break;
                case SPECIES:
                    system("clear");
                    view_species(speciesnames);
                    int specieViewChoice;
                    int specieDelChoice;
                    cin >> specieViewChoice;
                    system("clear");
                    species.at(specieViewChoice-1)->print_information();
                    cout << "1. Delete 2.Back" << endl;
                    cout << "Enter your choice: ";
                    cin >> specieDelChoice;
                    if (specieDelChoice == 1){
                        speciesnames.erase(speciesnames.begin() +  specieViewChoice-1);
                        deleteSpecie(species, specieViewChoice);
                        read_data(roles, species, rolenames, speciesnames);
                        system("clear");
                    }
                    else{
                        break;
                    }
                    break;
                case INDIVIDUALS:
                    system("clear");
                    if (beings.size() > 0){
                        view_beings(beings);
                        int individualChoice;
                        int goBack;
                        cin >> individualChoice;
                        system("clear");
                        beings.at(individualChoice-1)->print_information();
                        system("pause");
                    }
                    else{
                        cout << "No Individuals exist.." << endl;
                        system("pause");
                    }
                    break;
                case dBACK:
                    break;
                default:
                break;
            }
            break;
        case QUIT:
            quit = 1;
            break;

        
        default:
            break;
        }

    }
}

void show_menu(){
    cout << "1. Create new Character" << endl;
    cout << "2. Display Characters"<< endl;
    cout << "3. Quit" << endl;
    cout << "Enter your choice: ";
}
void create_role(vector<Role *> &roles, vector<string> &rolenames){
    string name;
    int minHealth= 0;
    int maxHealth= 0;
    int minStrength= 0;
    int maxStrength= 0;
    int minIntelligence = 0;
    int maxIntelligence= 0;

    cout << "create new role" << endl;
    cout << "name: ";
    cin >> name;
    cout << "\nMininum health: ";
    cin >> minHealth;
    cout << "\nMaximum health: ";
    cin >> maxHealth;
    cout << "\nMininum Strength: ";
    cin >> minStrength;
    cout << "\nMaximum Strength: ";
    cin >> maxStrength;
    cout << "\nMininum Intelligence: ";
    cin >> minIntelligence;
    cout << "\nMaximum Intelligence: ";
    cin >> maxIntelligence;

    roles.push_back(new Role(name, minHealth, maxHealth, minStrength, maxStrength, minIntelligence, maxIntelligence));
    rolenames.push_back(name);
    ofstream roleData("resources/roles.txt", ios_base::app);
    roleData << "\n";
    roleData << "Person " << name << " " << minHealth << " " << maxHealth << " " << minStrength << " " << maxStrength << " "  << minIntelligence << " " << maxIntelligence << " ";

    cout << "Created role " << name << endl;
}

void view_roles(vector<string> rolenames){
    for(int i = 0; i < rolenames.size(); i++){
        cout << i+1 << ". " << rolenames.at(i) << endl;
    };
    cout << "Enter your choice: ";
}

void view_beings(vector<Being *> beings){
    for(int i = 0; i<beings.size(); i++){
        cout << i+1 << ". " << beings.at(i)->name << endl;
    }
    cout << "Enter your choice: ";
};


void create_species(vector<Species *> &species, vector<string> &speciesnames, bool isEldrich){
    string name;
    int health= 0;

    int strength= 0;

    int intelligence = 0;

    bool natural;

    int disquiet;

    int traumatism = 4;

    string type;

    cout << "create new species" << endl;
    cout << "name: ";
    cin >> name;
    cout << "\nHealth: ";
    cin >> health;
    cout << "\nStrength: ";
    cin >> strength;
    cout << "\nIntelligence: ";
    cin >> intelligence;
    cout << "\nNatural: "; 
    cin >> natural;
    cout << "\nDisquiet: ";
    cin >> disquiet;
    if (isEldrich == 1){
        cout << "\nTraumatism";
        cin >> traumatism;
        type = "Eldritch";
    }
    else {
        type = "Creature";
    }
       // Species(string name, int health, int strength, int intelligence, bool natural, int disquiet)
    species.push_back(new Species(name,type, health, strength, intelligence, natural, disquiet, traumatism));
    speciesnames.push_back(name);
    ofstream speciesData("resources/species.txt", ios_base::app);
    speciesData << "\n";
    speciesData << type << " " << name << " " << health << " " << strength << " " << intelligence << " " << natural << " "  << disquiet << " " << traumatism << " ";

    cout << "Created Species: " << name << endl;
}
void view_species(vector<string> speciesnames){
    for(int i = 0; i < speciesnames.size(); i++){
        cout << i+1 << ". " << speciesnames.at(i) << endl;
    };
    
}

void read_data(vector<Role *> &roles, vector<Species *> &species, vector<string> &rolenames, vector<string> &speciesnames){
    string line;
    for (int i = 0; i<roles.size(); i++){
        delete roles.at(i);
    }
    for (int i = 0; i<species.size(); i++){
        delete species.at(i);
    }
    roles.clear();
    rolenames.clear();
    species.clear();
    speciesnames.clear();
    ifstream roleData("resources/roles.txt");
    char split = ' ';
    vector<string> rolewords;
    if (roleData.is_open()){
        while ( getline (roleData, line, split) ){
            rolewords.push_back(line);
            if (rolewords.size() == 8){
                roles.push_back(new Role(rolewords.at(1), stoi(rolewords.at(2)),  stoi(rolewords.at(3)), stoi(rolewords.at(4)), stoi(rolewords.at(5)), stoi(rolewords.at(6)), stoi(rolewords.at(7))));
                rolenames.push_back(rolewords.at(1));
                rolewords.clear();
            }
        }
        roleData.close();
    }
    ifstream speciesData("resources/species.txt");
    vector<string> specieswords;
    if (speciesData.is_open()){
        
        while ( getline (speciesData, line, split)){
            specieswords.push_back(line);
            if (specieswords.size() == 8){
                
                species.push_back(new Species(specieswords.at(1),specieswords.at(0), stoi(specieswords.at(2)), stoi(specieswords.at(3)), stoi(specieswords.at(4)), stoi(specieswords.at(5)), stoi(specieswords.at(6)), stoi(specieswords.at(7))));
                speciesnames.push_back(specieswords.at(1));
                specieswords.clear();
            }
        }
    }
}

void deleteRole(vector<Role *> &roles, int at){
    ofstream rolesData("resources/roles.txt");
    if (rolesData.is_open()){
        for (int i = 0; i<roles.size(); i++){
            if (roles.at(i)->name != roles.at(at-1)->name){
                rolesData << "Person " << roles.at(i)->name << " " << roles.at(i)->minH << " " << roles.at(i)->maxH << " " << roles.at(i)->minS << " " << roles.at(i)->maxS << " "  << roles.at(i)->minI << " " << roles.at(i)->maxI << " ";
                if (i != roles.size()-1){
                    rolesData << "\n";
                }
                
            }
        }
        rolesData.close();
    }
    
};

void deleteSpecie(vector<Species *> &species, int at){
    ofstream speciesData("resources/species.txt");
    if (speciesData.is_open()){
        for(int i = 0; i<species.size(); i++){
            if (species.at(i)->name != species.at(at-1)->name){
                speciesData << species.at(i)->type << " " << species.at(i)->name << " " << species.at(i)->health << " " << species.at(i)->strength << " " << species.at(i)->intelligence << " " << species.at(i)->natural << " "  << species.at(i)->disquiet << " " << species.at(i)->traumatism << " ";
            }
        }
        speciesData.close();
    }
    
}
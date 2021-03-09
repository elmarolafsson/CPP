#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <random>
#include <chrono>
using namespace std;

class Being {

public:
    
    Being(){
        health = 0;
        strength = 0;
        intelligence = 0;
    }
    Being(int health, int strength, int intelligence){
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
    Person(string name, string role, string gender, int health, int strength, int intelligence, int fear) : Being(health,strength,intelligence){
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
        Person::print_information();
        cout << "Terror: " << terror << endl;
    }
private:
    int terror;
};

class Creature : public Being {
public:
    Creature() : Being(){
        
    }
    Creature(string name, string species, int health, int strength, int intelligence, bool natural, int disquiet) : Being(health,strength,intelligence){
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
    Eldritch(string name,string species, int health, int strength, int intelligence, int traumatism) : Creature(name,species, health, strength, intelligence, 1, 10){
        this->traumatism = traumatism;
    }
    virtual void print_information(){
        Creature::print_information();
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

    Species(){
        this->count = 0;
    }
    Species(string name, int health, int strength, int intelligence, bool natural, int disquiet){
        this->name = name;
        this->health = health;
        this->strength = strength;
        this->intelligence = intelligence;
        this->natural = natural;
        this->disquiet = disquiet;
    }
    virtual void print_information(){
        cout << "Creature" << endl;
        cout << "Species: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Strength: " << strength << endl;
        cout << "Intelligence: " << intelligence << endl;
        cout << "Natural: " << natural << endl;
        cout << "Disquiet: " << disquiet << endl;
    }

};
class Role{
public:
    string name;
    int health;
    int strength;
    int intelligence;
    int fear;
    int terror;

    Role(){

    }
    Role(string name, int health, int strength, int intelligence){
        this->name = name;
        this->health = health;
        this->strength = strength;
        this->intelligence = intelligence;
        this->fear = fear;
        this->terror = terror;
    }
    virtual void print_information(){
        cout << "Person" << endl;
        cout << "Role: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Strength: " << strength << endl;
        cout << "Intelligence: " << intelligence << endl;
    }

};


void create_role(vector<Role *> &roles, vector<string> &rolenames);
void create_species(vector<Species *> &species, vector<string> &speciesnames);
void view_roles(vector<string> rolenames);
void view_species(vector<string> speciesnames);
void show_menu();



int main() {
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));

    vector<Species *> species;
    vector<Role *> roles;
    vector<Being *> beings;
    vector<string> rolenames;
    vector<string> speciesnames;
    int selection;
    int choice = 0;
    
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
    string name;
    string gender;
    while (quit == 0)
    {
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
            cin >> choice;
            switch (choice)
            {
            case PERSON:
                system("clear");
                if(rolenames.size() == 0)
                {
                    create_role(roles,rolenames);
                }

                cout << "Input " << rolenames.size() + 1 << " to create new Role: " << endl;
                cout << "Select Role: " << endl;
                view_roles(rolenames);
                int pickRole;
                cin >> pickRole;
                
                if (pickRole == rolenames.size() + 1){
                    create_role(roles, rolenames);
                }
                else{

                    cout << "Create person with role: " << rolenames.at(pickRole-1) << endl;
                    cout << "Enter Name: ";
                    cin >> name;
                    cout << "Enter Gender: ";
                    cin >> gender;
                    // Person(name, role, gender, health, strength, intelligence, fear)
                    beings.push_back(new Person(name, rolenames.at(pickRole-1), gender, roles.at(pickRole-1)->health, roles.at(pickRole-1)->strength, roles.at(pickRole-1)->intelligence, 0));
                }
                break;
            case CREATURE:
                system("clear");
                if(speciesnames.size() == 0)
                {
                    create_species(species,speciesnames);
                }

                cout << "Select species" << endl;
                cout << "Input " << speciesnames.size() + 1 << " to create new species: " << endl;
                view_species(speciesnames);
                int pickSpecies;
                cin >> pickSpecies;
                if (pickSpecies == speciesnames.size() + 1){
                    create_species(species, speciesnames);
                }
                else{
                    cout << "Create new " << speciesnames.at(pickSpecies-1) << endl;
                    species.at(pickSpecies-1)->count++;
                    name = speciesnames.at(pickSpecies-1) + " " + to_string(species.at(pickSpecies-1)->count);
                    beings.push_back(new Creature(name, speciesnames.at(pickSpecies-1), species.at(pickSpecies-1)->health, species.at(pickSpecies-1)->strength,species.at(pickSpecies-1)->intelligence,species.at(pickSpecies-1)->natural,species.at(pickSpecies-1)->disquiet));
                }
                break;
            case INVESTIGATOR:
                cout << "creating an investigator" << endl;
                break;
            case ELDRITCH:
                cout << "creating an eldritch horror" << endl;
                break;
            case BACK:
                show_menu();
                break;

            default:
                break;
            } 
        case DISPLAY:
            system("clear");
            cout << "--------------" << "\nBeings\n" << "--------------" << endl;
            for (Being *b : beings){
                b->print_information();
                cout << endl;
            }
            cout << "--------------" << "\nRoles\n" << "--------------" << endl;
            for (Role *b : roles){
                b->print_information();
                cout << endl;
            }
            cout << "--------------" << "\nSpecies\n" << "--------------" << endl;
            for (Species *b : species){
                b->print_information();
                cout << endl;
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

    roles.push_back(new Role(name, rand() % (maxHealth - minHealth+1) + minHealth, rand() %(maxStrength - minStrength+1)+minStrength, rand() % (maxIntelligence - minIntelligence+1)+minIntelligence));
    rolenames.push_back(name);
    cout << "Created role " << name << endl;
}

void view_roles(vector<string> rolenames){
    for(int i = 0; i < rolenames.size(); i++){
        cout << i+1 << ". " << rolenames.at(i) << endl;
    };
}
void create_species(vector<Species *> &species, vector<string> &speciesnames){
    string name;
    int health= 0;

    int strength= 0;

    int intelligence = 0;

    bool natural;

    int disquiet;

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
       // Species(string name, int health, int strength, int intelligence, bool natural, int disquiet)
    species.push_back(new Species(name, health, strength, intelligence, natural, disquiet));
    speciesnames.push_back(name);
    cout << "Created Species: " << name << endl;
}
void view_species(vector<string> speciesnames){
    for(int i = 0; i < speciesnames.size(); i++){
        cout << i+1 << ". " << speciesnames.at(i) << endl;
    };
}
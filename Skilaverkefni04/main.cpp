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
        cout << "Person" << endl;
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
    Creature(int health, int strength, int intelligence, bool natural, int disquiet) : Being(health,strength,intelligence){
        this->natural = natural;
        this->disquiet = disquiet;
    }
    virtual void print_information(){
        cout << "Creature" << endl;
        cout << "Health: " << health << endl;
        cout << "Strength: " << strength << endl;
        cout << "Intelligence: " << intelligence << endl;
        cout << "Natural: " << natural << endl;
        cout << "Disquiet: " << disquiet << endl;
    }
protected:
    bool natural;
    int disquiet;
};
class Eldritch : public Creature{
public: 
    Eldritch() : Creature(){

    }
    Eldritch(int health, int strength, int intelligence, int traumatism) : Creature(health, strength, intelligence, 1, 10){
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

    Species(){

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
        cout << "Species: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Strength: " << strength << endl;
        cout << "Intelligence: " << intelligence << endl;
    }

};


void create_role(vector<Role *> &roles, vector<string> &rolenames);
void view_roles(vector<string> rolenames);
void show_menu();



int main() {
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));

    vector<Species *> species;
    vector<Role *> roles;
    vector<Being *> beings;
    int selection;
    int choice = 0;
    vector<string> rolenames;
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
    while (!quit)
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
                else{
                    cout << "Select Role: " << endl;
                    view_roles(rolenames);
                }
                cout << "Select Role: " << endl;
                view_roles(rolenames);
                int pickRole;
                cin >> pickRole;
                cout << "Create person with role: " << rolenames.at(pickRole-1) << endl;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Gender: ";
                cin >> gender;
                // Person(name, role, gender, health, strength, intelligence, fear)
                beings.push_back(new Person(name, rolenames.at(pickRole-1), gender, roles.at(pickRole-1)->health, roles.at(pickRole-1)->strength, roles.at(pickRole-1)->intelligence, 0));
                
                break;
            case CREATURE:
                cout << "creating a creature" << endl;
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
        case QUIT:
            quit = 1;
            break;

        
        default:
            break;
        }

    }

    for (Being *b : beings){
        b->print_information();
        cout << endl;
    }
    species.push_back(new Species("Elmar",6,3,6,1,9));
    species.push_back(new Species("Ugla",6,3,6,1,9));
    for (Species *b : species){
        b->print_information();
        cout << endl;
    }
    roles.push_back(new Role("Pianost", 6,4,9));
    for (Role *b : roles){
        b->print_information();
        cout << endl;
    }
}

void show_menu(){
    system("clear");
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
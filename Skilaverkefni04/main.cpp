#include <iostream>
#include <string>
#include <vector>
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
    Person(int health, int strength, int intelligence, string gender, int fear) : Being(health,strength,intelligence){
        this->gender = gender;
        this->fear = fear;
    }
    virtual void print_information(){
        cout << "Person" << endl;
        cout << "Health: " << health << endl;
        cout << "Strength: " << strength << endl;
        cout << "Intelligence: " << intelligence << endl;
        cout << "Gender: " << gender << endl;
        cout << "Fear: " << fear << endl;
    }
protected:
    string gender;
    int fear;
};
class Investigator : public Person{
public:
    Investigator(): Person(){

    }
    Investigator(int health, int strength, int intelligence, string gender, int fear, int terror) 
        : Person(health, strength, intelligence, gender, fear){
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

void show_menu();

int main() {
    vector<Being *> beings;
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
    while (!quit)
    {
        show_menu();
        cin >> selection;
        switch (selection)
        {
        case CREATE:
            cout << "1. Person" << endl;
            cout << "2. Investigator" << endl;
            cout << "3. Creature" << endl;
            cout << "4. Eldritch horror" << endl;
            cout << "5. Go back" << endl;
            cin >> choice;
            switch (choice)
            {
            case PERSON:
                cout << "Creating a person" << endl;
                
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Gender: ";
                cin >> gender;
                cout << name << " " << gender << endl;
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

            default:
                break;
            }
            
            
        
        default:
            break;
        }

    }
    
    beings.push_back(new Person(4, 3, 2, "female", 10));
    beings.push_back(new Eldritch(8, 4, 6, 9));
    beings.push_back(new Investigator(5, 7, 4, "male", 7, 2));
    beings.push_back(new Creature(5, 9, 4, 1, 10));

    for (Being *b : beings){
        b->print_information();
        cout << endl;
    }
}

void show_menu(){
    cout << "1. Create new character" << endl;
    cout << "2. Display characters"<< endl;
    cout << "3. Quit" << endl;
}
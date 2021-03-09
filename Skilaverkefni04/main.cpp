#include <iostream>
#include <string>
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
    friend ostream &operator<<(ostream &out, const Person &org){
        out << "health: " << org.health << " strength: " << org.strength << " Intelligence " << org.intelligence 
            << " gender: " << org.gender << " fear: " << org.fear;
        return out;
    }
private:
    string gender;
    int fear;
};


int main() {
    Person person(5, 2, 1, "male", 10);
    cout << person << endl;
}
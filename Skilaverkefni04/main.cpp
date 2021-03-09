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
    friend ostream &operator<<(ostream &out, const Investigator &org){
        out << "health: " << org.health << " strength: " << org.strength << " Intelligence " << org.intelligence 
            << " gender: " << org.gender << " fear: " << org.fear << " terror " << org.terror;
        return out;
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
    friend ostream &operator<<(ostream &out, const Creature &org){
        out << "health: " << org.health << " strength: " << org.strength << " Intelligence " << org.intelligence 
            << " natural: " << org.natural << " disquiet: " << org.disquiet;
        return out;
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
private:
    int traumatism;
};

int main() {
    Person person(5, 2, 1, "male", 10);
    Creature creature(8,3,4,1,8);
    Investigator inv(4,6,2,"female",5,1);
    cout << inv << endl;
    cout << creature << endl;
    cout << person << endl;
}
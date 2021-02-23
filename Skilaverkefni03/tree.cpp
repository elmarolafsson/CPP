#include <iostream>
#include <vector>
#include <string>
#include "characters.h"
using namespace std;

class tree
{
private:
    /* data */
    vector<string> _lines;
    characters _chars[26];
public:
    tree(vector<string> lines, characters chars[]);
    void printLines();
    ~tree();
};

tree::tree(vector<string> lines, characters chars[])
{
    _lines = lines;
    _chars = chars;
}

tree::~tree()
{
}

void tree::printLines(){
    for (int i = 0; i < _lines.size(); i++){
        cout << _lines.at(i) << endl;
    }
}
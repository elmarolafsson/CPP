#include <iostream>
#include <vector>
#include <string>
#include "tree.h"
using namespace std;


class Tree
{
private:
    /* data */
    vector<string> _lines;
    struct characters *_chars;
public:
    Tree(vector<string> lines, struct characters *chars);
    void printLines();
    ~Tree();
};


Tree::Tree(vector<string> lines, struct characters *chars)
{
    _lines = lines;
    _chars = chars;

}

Tree::~Tree()
{
}

void Tree::printLines(){
    for (int i = 0; i < _lines.size(); i++){
        cout << _lines.at(i) << endl;
    }
}
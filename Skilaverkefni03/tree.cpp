#include <iostream>
#include <vector>
#include <string>
#include "chars.h"
#include "tree.h"
using namespace std;

Node::Node(int count, char c ,Node *left, Node *right, Node *parent){
    this->count = count;
    this->c = c;
    this->left = left;
    this->right = right;
    this->parent = parent;
}

Node::~Node(){
    if (left != NULL){
        delete left;
    }
    if (right != NULL){
        delete right;
    }
    if (parent != NULL){
        delete parent;
    }
}

ostream& operator<<(ostream& out, const Node *node){
    if (node != NULL){
        out << node->left;
        out << node->count;
        out << node->c;
        out << node->right;
        out << " " << node->parent;
    }
    return out;
}
    
   


// class Tree
// {
// private:
//     /* data */
//     vector<string> _lines;
//     struct characters *_chars;
// public:
//     Tree(vector<string> lines, struct characters *chars);
//     void printLines();
//     ~Tree();
// };


// Tree::Tree(vector<string> lines, struct characters *chars)
// {
//     _lines = lines;
//     _chars = chars;

// }

// Tree::~Tree()
// {
// }

// void Tree::printLines(){
//     for (int i = 0; i < _lines.size(); i++){
//         cout << _lines.at(i) << endl;
//     }
// }
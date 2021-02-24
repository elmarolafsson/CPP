#include <iostream>
#include <vector>
#include <string>
#include "chars.h"
#include "tree.h"
using namespace std;
DataClass::DataClass(int count, char c){
    this->count = count;
    this->c = c;
}
ostream& operator<<(ostream& out, const DataClass *dc){
    if(dc != NULL){
        out << "{ " << dc->count << " " << dc->c << " }"; 
    }
    return out;

}
Node::Node(DataClass *data,Node *left, Node *right){
    this->data = data;
    this->left = left;
    this->right = right;
    this->value = 0;
}

Node::~Node(){
    if (left != NULL){ 
        delete left;
    }
    if (right != NULL){
        delete right;
    }
    if (data != NULL){
        delete data;
    }
}

ostream& operator<<(ostream& out, const Node *node){
    if (node != NULL){
        out << node->left;
        out << node->data;
        out << node->right;
        
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
#include <iostream>

using namespace std;

class Node{
public:
    Node(int count, char c, Node *left = NULL, Node *right = NULL);
    virtual ~Node();
    friend ostream& operator <<(ostream& out, const Node *node);

private:
    int count;
    char c;
    Node *left;
    Node *right;
};
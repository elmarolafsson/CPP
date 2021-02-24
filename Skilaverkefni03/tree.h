#include <iostream>

using namespace std;

class DataClass{
    public:
        DataClass(int count, char c);
        friend ostream& operator <<(ostream& out, const DataClass *dc);

        int count;
        char c;
};

class Node{
public:
    Node(DataClass *data = NULL, Node *left = NULL, Node *right = NULL);
    virtual ~Node();
    friend ostream& operator <<(ostream& out, const Node *node);
    DataClass *data;
    Node *left;
    Node *right;
    Node *root;
    Node *parent;
    vector<Node *> children;
    int value;

private:
    
};
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <deque>
//#include "chars.h"
#include "tree.h"

using namespace std;

struct characters{
    int count;
    char c;
};

int getUniqueChars(vector<string> s);

void sort(characters ch[]);

int main(){
    char c;
    string some_string;
    ifstream myfile;
    characters chars[26] = {0};
    vector<string> lines;
    int curr_root = 0;
    Node *tree = NULL;
    Node *node = NULL;
    deque<Node *> node_queue;
    vector<Node *> parents;

    // Get number of unique characters
    myfile.open("test.txt");
    int num_chars;
    string line;
    

    while (getline(myfile, line)){ // Issue it here.
        lines.push_back(line);
    }

    myfile.close();
    for (int i = 0; i < lines.size(); i++){
        cout << lines.at(i) << endl;
    }
    num_chars = getUniqueChars(lines);
    cout << "num: " << num_chars << endl;

    // Get count of each character into a struct
    for (int i = 0; i < lines.size(); i++){
        string curr = lines.at(i);
        for (int j = 0; j < curr.length(); j++){
            const int id = curr[j] - 'a';
            ++chars[id].count;
            chars[id].c = curr[j];
        }
    }
    sort(chars);
    characters newchars[num_chars];
    int newcharsCount = 0;
    for (int i = 0; i < 26; i++){
        if (chars[i].count > 0){
            newchars[newcharsCount].c = chars[i].c;
            newchars[newcharsCount].count = chars[i].count;
            newcharsCount++;
        }
    }

    

    for (int i = 0; i < 26; i++){
        if (newchars[i].count > 0){
            cout << newchars[i].c << ": " << newchars[i].count << "  " << endl;
        }
    }
    node = new Node(new DataClass(newchars[0].count,newchars[0].c));
    node_queue.push_back(node);
    curr_root = newchars[0].count;

    for (int i = 1; i < num_chars; i++){
        //Node *z = new Node(chars[0].count + chars[1].count, 'z', (new Node(chars[0].count, chars[0].c, NULL, NULL)), (new Node(chars[1].count, chars[1].c, NULL, NULL)));
        node = new Node(new DataClass(newchars[i].count,newchars[i].c));
        node_queue.push_back(node);
        curr_root = curr_root + newchars[i].count;
        node = new Node(new DataClass(curr_root,'-'));
        node_queue.push_back(node);
    }
    while(!node_queue.empty()){
        Node *myNode = new Node();
        
        if (node_queue.back()->data->c == '-'){
            cout << "im stuck" << endl;
            myNode = node_queue.back();
            for (int i = 0; i < 2; i++){
                node_queue.pop_back();
                myNode->children.push_back(node_queue.back());
            }
        }
        
        else{
            node_queue.pop_back();
        }
        parents.push_back(myNode);

    }

    for (int i = 0; i < parents.size(); i++){
        cout << parents.at(i) << " is parent of " << parents.at(i)->children.at(0) << " with value: " << parents.at(i)->children.at(0)->value << " and " << parents.at(i)->children.at(1) << " with value " << parents.at(i)->children.at(1)->value  << endl;
        if(parents.at(i)->children.at(0)->data->count > parents.at(i)->children.at(1)->data->count){
            parents.at(i)->children.at(0)->value = 1;
            parents.at(i)->children.at(1)->value = 0;
        }
        else{
            parents.at(i)->children.at(1)->value = 1;
            parents.at(i)->children.at(0)->value = 0;
        }
    }

    // tree = node;

    // cout << "tree: " << endl;
    // tree->root = node_queue.back();
    // node_queue.pop_back();
    // tree->root->children.push_back(node_queue.back());
    // cout << "root: " << tree->root << endl;
    // cout << "child of root: " << tree->root->children[]9;
    

    //Tree myTree = Tree(lines, chars);
    //myTree.printLines();
    return 0;
}

int getUniqueChars(vector<string> s){
    map<char,int> m;
    for (int i = 0; i < s.size(); i++){
        for (int j = 0; j < s.at(i).length(); j++){
            m[s.at(i)[j]];
        }
    }
    return m.size();
}

void sort(characters ch[]){
    characters temp;
    for (int i = 0; i < 26; i++){
       for (int j = i+1; j<26; j++){
            if (ch[j].count != 0){
                if (ch[j].count < ch[i].count){
                    temp.c = ch[i].c;
                    temp.count = ch[i].count;
                    ch[i].c = ch[j].c;
                    ch[i].count = ch[j].count;
                    ch[j].c = temp.c;
                    ch[j].count = temp.count;
                }
            }
        }
    }
}
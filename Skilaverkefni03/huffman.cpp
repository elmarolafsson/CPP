#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <array>
#include "chars.h"
#include "tree.h"

using namespace std;


int getUniqueChars(vector<string> s);

characters sort(characters ch[]);

int main(){
    char c;
    string some_string;
    ifstream myfile;
    struct characters chars[26] = {0};
    vector<string> lines;

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

    chars = sort(chars);

    for (int i = 0; i < 26; i++){
        if (chars[i].count > 0){
            cout << chars[i].c << ": " << chars[i].count << "  " << endl;
        }
    }
    

    Node *tree_node = new Node(chars[0].count, chars[0].c, NULL, NULL);

    cout << "tree node: " << tree_node << endl;

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

characters sort(characters ch[]){
    characters temp;
    for (int i = 0; i < 26; i++){
        for (int j = i+1; j<26; j++){
            cout << ch[j].c << ":" << ch[i].c << endl;
            // if (ch[j].count < ch[i].count){
            //     temp.c = ch[i].c;
            //     temp.count = ch[i].count;
            //     ch[i].c = ch[j].c;
            //     ch[i].count = ch[j].count;
            //     ch[j].c = temp.c;
            //     ch[j].count = temp.count;
            // }
        }
    }
    return ch;
}
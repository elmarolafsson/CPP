#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "tree.cpp"
#include "characters.h"
using namespace std;


int getUniqueChars(vector<string> s);

int main(){
    char c;
    string some_string;
    ifstream myfile;
    characters chars[26] = {0};
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

    for (int i = 0; i < 24; i++){
        if (chars[i].count > 0){
            cout << chars[i].c << ": " << chars[i].count << "  " << endl;
        }
    }
    tree myTree = tree(lines, chars);
    myTree.printLines();
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
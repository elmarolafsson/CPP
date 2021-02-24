#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
//#include "chars.h"
#include "tree.h"

using namespace std;

struct characters{
    int count;
    char c;
};

int getUniqueChars(vector<string> s);

void sort(characters ch[]);

void write(map<char, string> codes, vector<string> lines, string filename);

string getNextWord(string command);
string getFirstWord(string command);

// string reverseStr(string str); 

int main(int argc, char *argv[]){
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
    
    string line;

    string arg = argv[1];
    if (arg == "-e"){
        map<char, string> codes;
        myfile.open(argv[2]);
        int num_chars;
        
        
        while (getline(myfile, line)){ 
            lines.push_back(line);
        }

        myfile.close();
        for (int i = 0; i < lines.size(); i++){
            cout << lines.at(i) << endl;
        }   
        // Get number of unique characters

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

        for (int i = 0; i < num_chars; i++){
            if (newchars[i].count > 0){
                cout << newchars[i].c << ": " << newchars[i].count << "  " << endl;
            }
        }
        node = new Node(new DataClass(newchars[0].count,newchars[0].c));
        node_queue.push_back(node);
        curr_root = newchars[0].count;

        for (int i = 1; i < num_chars; i++){
            node = new Node(new DataClass(newchars[i].count,newchars[i].c));
            node_queue.push_back(node);
            curr_root = curr_root + newchars[i].count;
            node = new Node(new DataClass(curr_root,'-'));
            node_queue.push_back(node);
        }
        while(!node_queue.empty()){
            Node *myNode = new Node();
            
            if (node_queue.back()->data->c == '-'){
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

        for (int i = 0; i < parents.size()-1; i++){
            
            if(parents.at(i)->children.at(0)->data->count > parents.at(i)->children.at(1)->data->count){
                parents.at(i)->children.at(1)->value.append("0"+parents.at(i)->value);
                parents.at(i)->children.at(0)->value.append("1"+parents.at(i)->value);
            }
            else{
                parents.at(i)->children.at(1)->value.append("1"+parents.at(i)->value);
                parents.at(i)->children.at(0)->value.append("0"+parents.at(i)->value);
            }
        }    

        for (int i = 0; i < num_chars; i++){
            for (int j = 0; j < parents.size()-1; j++){
                if (newchars[i].c == parents.at(j)->children.at(0)->data->c){
                    reverse(parents.at(j)->children.at(0)->value.begin(),parents.at(j)->children.at(0)->value.end());
                    codes[newchars[i].c] = parents.at(j)->children.at(0)->value;
                }
                else if (newchars[i].c == parents.at(j)->children.at(1)->data->c){
                    reverse(parents.at(j)->children.at(1)->value.begin(),parents.at(j)->children.at(1)->value.end());
                    codes[newchars[i].c] = parents.at(j)->children.at(1)->value;
                }
            }
        }

        for (const auto& x : codes) {
            cout << x.first << " : " << x.second << endl;
        }

        write(codes, lines, argv[3]);
    }
    else if (arg == "-d"){
        map<string, string> codes;
        bool done = 0;
        myfile.open(argv[2]);
        while (getline(myfile, line)){
            if (getFirstWord(line) == "\\"){
                done = 1;
            }
            else if (done == 0){
                codes[getFirstWord(line)] = getNextWord(line);
            }
            else{
                lines.push_back(line);
            }
        }

        for (const auto& x : codes) {
            cout << x.first << " " << x.second << endl;
        }
        for(int i = 0; i < lines.size(); i++){
            cout << lines.at(i) << endl;
        }
    }
                

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

void write(map<char, string> codes, vector<string> lines, string filename){
    ofstream file;
    file.open (filename);
    for (const auto& x : codes) {
        file << x.first << " " << x.second << "\n";
    }
    file << "\\" << "\n";
    file << endl;
    for (int j = 0; j<lines.size();j++) {
        for (char const &c: lines.at(j)) {
            for (const auto& x : codes) {
                if (c == x.first){
                    file << x.second;
                }
                
            }
            
        }
        file << "\n";
    }
    file.close();
}

string getNextWord(string command) {
    return command.substr(command.find(" ") + 1);
}

string getFirstWord(string command) {
    return command.substr(0, command.find(" "));
}
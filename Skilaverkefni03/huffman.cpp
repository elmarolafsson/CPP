#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

struct characters{
    int count;
    char c;
};

int getUniqueChars(string s);

int main(){
    char c;
    string some_string;
    ifstream myfile;
    characters chars[26] = {0};

    // Get number of unique characters
    myfile.open("test.txt");
    myfile >> some_string;
    int num_chars = getUniqueChars(some_string);
    myfile.close();

    myfile.open("test.txt");
    while (myfile >> c){
        const int id = c - 'a';
        ++chars[id].count;
        chars[id].c = c;
    }
    myfile.close();
    for (int i = 0; i < num_chars; i++){
        cout << chars[i].c << ": " << chars[i].count << "  " << endl;
    }


    return 0;
}

int getUniqueChars(string s){
    map<char,int> m;
    for (int i = 0; i < s.length(); i++){
        m[s[i]]++;
    }


    return m.size();
}
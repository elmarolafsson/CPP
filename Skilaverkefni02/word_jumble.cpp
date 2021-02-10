#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream word;
    word.open("words.txt");
    cout << word << endl;
    return 0;
}
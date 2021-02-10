#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <rand_word.h>
using namespace std;
char getword(Word F){
    
}
int main(){
    Word B;
    B.get_word("words.txt");
    ifstream word;
    char line[120];
    int counter = 0;
    srand (time(NULL));
    word.open("words.txt");
    while (word >> line){
        counter++;
    }
    word.close();
    word.open("words.txt");
    int v1 = rand() % counter + 1;
    for (int i=0; i<v1; i++){
        word.getline(line, 120);
    }
    cout << line << endl;
    return 0;
}
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "rand_word.h"
#include <string.h>

using namespace std;

int main(){
    
    Word B;
    char filename[25] = "words.txt";
    char* word = B.get_word(filename);
    for (int i=0;i<strlen(word);i++){
        B.unscrambled[i] = word[i];
    }
    B.randomize(word, strlen(word));
    cout << B.unscrambled << "->" << word << endl;
    return 0;
}
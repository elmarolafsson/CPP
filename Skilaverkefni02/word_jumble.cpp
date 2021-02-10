#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "rand_word.h"
#include <string.h>

using namespace std;

int main(){
    srand (time(NULL));
    Word B;
    char filename[120] = "words.txt";
    char* word = B.get_word(filename);
    
    B.randomize(word, strlen(word));
    cout << word << endl;
    return 0;
}
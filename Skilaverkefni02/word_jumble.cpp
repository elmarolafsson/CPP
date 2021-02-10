#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "rand_word.h"
#include <string.h>

using namespace std;

int main(){
    
    Word B;
    char filename[120] = "words.txt";
    char *word = B.get_word(filename);
    cout << word << endl;
    B.randomize(word, strlen(word));
    cout << word << endl;
    
    return 0;
}
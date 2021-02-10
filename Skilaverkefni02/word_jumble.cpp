#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "rand_word.h"
#include <string.h>

using namespace std;

int main(){
    
    Word B;;
    char filename[120] = "words.txt";
    char* word = B.get_word(filename);
    B.set_word(word, strlen(word));
    B.scramble(word, strlen(word));
    cout << B.unscrambled << endl;
    cout << B.scrambled << endl;
    return 0;
}
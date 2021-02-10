#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "rand_word.h"
#include <string.h>

using namespace std;

int main(){
    srand(time(NULL));
    int counter = 0;
    while (counter < 5){
        Word *B;
        B = new Word;
        char filename[64] = "words.txt";
        B->get_word(filename);
        B->scramble(B->unscrambled, strlen(B->unscrambled));
        cout << B->unscrambled << endl;
        cout << B->scrambled << endl;
        delete B;
        counter ++;
        
    }
    return 0;
}
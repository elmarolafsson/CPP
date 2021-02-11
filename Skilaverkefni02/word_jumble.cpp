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
        bool fail = true;
        while (fail){
            cout << B->scrambled << endl;
            char userWord[64];
            cout << "Input your guess" << endl;
            cin >> userWord;
            B->compare(B->unscrambled, userWord);
            cout << B->guess << endl;
            if (B->guess == true){
                cout << "YOU DID IT!" << endl;
                fail = false;
            }
            else{
                cout << "try again" << endl;
            }
            
            
        }
        delete B;
        counter ++;
    }
    return 0;
}
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include "rand_word.h"
#include <string.h>

using namespace std;

int main(){
    srand(time(NULL));
    int counter = 0;
    bool play = true;
    while (play){
        
        Word *B;
        B = new Word;
        char filename[64] = "words.txt";
        B->get_word(filename);
        B->scramble(B->unscrambled, strlen(B->unscrambled));
        bool fail = true;
        while (fail){
            system("CLS");
            cout << "Word to guess: " << B->scrambled << endl;
            char userWord[64];
            cout << "Input your guess: ";
            cin >> userWord;
            B->compare(B->unscrambled, userWord);
            if (B->guess == true){
                cout << "YOU DID IT!" << endl;
                fail = false;
            }
            else{
                cout << "try again" << endl;
            }
            char ans;
            cout << "Continue? y/n ";
            cin >> ans;
            if (ans == 'n'){
                play = false;
                break;
            }
        }
        delete B;
        counter ++;
    }
    return 0;
}
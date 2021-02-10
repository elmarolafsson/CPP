#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Word{

    public:
        Word();
        char *get_word(char filename[]);

        void swap(char *a, char *b);
        void scramble(char arr[], int n);
        void set_word(char word[]);
        

        char unscrambled[25];
        char scrambled[25];
};
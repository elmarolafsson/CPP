#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;

class Word{

    public:
        Word();
        void get_word(char filename[]);

        void swap(char *a, char *b);
        void scramble(char arr[], int n);
        void set_word(char word[], int n);
        

        char unscrambled[64];
        char scrambled[64];
};
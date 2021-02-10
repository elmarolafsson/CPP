#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Word{

    public:
        char* get_word(char filename[]){
            ifstream word;
            char* line[120];
            int counter = 0;
            srand (time(NULL));
            word.open(filename);
            while (word >> *line){
                 counter++;
            }
            word.close();
            word.open(filename);
            int v1 = rand() % counter + 1;
            for (int i=0; i<v1; i++){
                word.getline(*line, 120);
            }
            return *line;
        }
        void swap(char *a, char *b){
            int temp = *a;
            *a = *b;
            *b = temp;
        }
        void randomize(char arr[], int n){
            srand(time(NULL));
            int i;
            for (i = n-1; i>0; i--){
                int j = rand() % (i+1);
                swap(&arr[i], &arr[j]);
            }
        }
};
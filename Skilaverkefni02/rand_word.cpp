
#include "rand_word.h"

Word::Word(){
    
}

        
char* Word::get_word(char filename[]){
    ifstream words;
    char* line[25];
    int counter = 0;
    srand (time(NULL));
    words.open(filename);
    while (words >> *line){
            counter++;
    }
    words.close();
    words.open(filename);
    int v1 = rand() % counter + 1;
    for (int i=0; i<v1; i++){
        words.getline(*line, 25);
    }
    return *line;
}
void Word::swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}
void Word::randomize(char arr[], int n){
    srand(time(NULL));
    int i;
    for (i = n-1; i>0; i--){
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }
}
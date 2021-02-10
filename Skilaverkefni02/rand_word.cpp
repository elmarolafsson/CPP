
#include "rand_word.h"

Word::Word(){
    
}

        
char *Word::get_word(char filename[]){
    ifstream words;
    char* line[120];
    int counter = 0;
    srand (time(NULL));
    words.open(filename);
    while (words >> *line){
            counter++;
    }
    words.close();
    *line = new char[120];
    words.open(filename);
    int v1 = rand() % counter + 1;
    for (int i=0; i<v1; i++){
        words.getline(*line, 120);
    }


    return *line;
}
void Word::swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}
void Word::scramble(char arr[], int n){
    srand(time(NULL));
    int i;
    for (i = n-1; i>0; i--){
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }
    for (int i = n; i>=0; i--){
        scrambled[i] = arr[i];
    }
}
void Word::set_word(char word[], int n){
    for (int i = n; i>=0; i--){
        unscrambled[i] = word[i];
    }
}


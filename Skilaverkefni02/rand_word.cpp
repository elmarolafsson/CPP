#include "rand_word.h"

Word::Word(){
    guess = false;
}
        
void Word::get_word(char filename[]){
    ifstream words;
    char* line[64];
    *line = new char[64];
    int counter = 0;
    words.open(filename);
    while (words >> *line){
            counter++;
    }
    words.close();
    *line = new char[64];
    words.open(filename);
    int v1 = rand() % counter + 1;
    for (int i=0; i<v1; i++){
        words.getline(*line, 64);
    }
    set_word(*line,strlen(*line));
}

void Word::swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}
void Word::scramble(char arr[], int n){
    for (int i = n; i>=0; i--){
        scrambled[i] = arr[i];
        dashed[i] = '-';
    }
    dashed[n] = '\0';
    int index = rand() % n;
    dashed[index] = unscrambled[index];
    for (int i = n-1; i>=0; i--){
        int j = rand() % (i+1);
        swap(&scrambled[i], &scrambled[j]);
    }
}

void Word::set_word(char word[], int n){
    for (int i = n; i>=0; i--){
        unscrambled[i] = word[i];
    }
}

void Word::compare(char word1[], char word2[]){
    int i = 0;
    bool tempBool = true;
    if (strlen(word1) == strlen(word2)){
        while (tempBool){
            if (word1[i] == word2[i]){
                if (i == strlen(word1)){
                    break;
                }
            }
            else{
                tempBool = false;
                break;
            }
            i++;
        }
    }
    else{
        tempBool = false;
    }
    guess = tempBool;
}

void Word::use_hint(){
    int index = rand() % strlen(unscrambled);
    if (guess == false){
        if (dashed[index] != unscrambled[index]){
            dashed[index] = unscrambled[index];
        }
        else{
            use_hint();
        }
    }
}
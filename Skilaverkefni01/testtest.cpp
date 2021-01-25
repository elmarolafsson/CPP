#include <iostream>

using namespace std;

// int main(){
//     char filename[] = "FILENAME";
//     size_t size = sizeof(filename)-1;
//     cout << filename[0] << endl;
//     cout << size << endl;
//     filename[size++] = '.';
//     filename[size++] = 'w';
//     filename[size++] = 'a';
//     filename[size++] = 'v';
//     cout << filename << endl;
// }

int main(int argc, char* argv[])
{
    int Size = 0;
    for (int i = 0; i > -1; i++){
        if ( argv[1][i] != '\0' ) Size++;
        else break;
    }   
    cout << Size << endl;
}
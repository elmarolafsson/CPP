#include <iostream>

using namespace std;

int main(){
    int a;
    char c = 'y';
    while(c != 'n') {
        cout << "how high should I count?: ";
        cin >> a;
        for (int counter = 1; counter <= a; ++counter) {
            cout << "the number is now " << counter << endl;
        }
        cout << "Do you wish to continue? y/n: ";
        cin >> c;
        if(c == 'y') {
            cout << "running it back up... " << endl;
        }
    }
    return 0;
}
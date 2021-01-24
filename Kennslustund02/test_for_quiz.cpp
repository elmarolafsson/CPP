#include <iostream>
using namespace std;

int main(){
    int some_integer = 10;
    //some_integer = some_integer << 5;
    cout << (some_integer << 5) << endl;
    short integer = 3627;
    cout << (integer & 0xff) << endl;
    int a[10], n, i;    
    cout<<"Enter the number to convert: ";    
    cin>>n;    
    for(i=0; n>0; i++){    
        a[i]=n%2;    
        n= n/2;  
    }    
    cout<<"Binary of the given number= ";    
    for(i=i-1 ;i>=0 ;i--){    
        cout<<a[i];    
    }    
} 
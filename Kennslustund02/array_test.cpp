#include <iostream>
#include <fstream>
//using namespace std;

int main(){
    std::cout << "hello" << std::endl;
    std::ofstream fyou;
    fyou.open("poop.txt", std::fstream::out);
    std::cout << fyou.bad() << std::endl; 
    int characters = 22;
    fyou << characters << std::endl;
    fyou.close();
    return 0;
}
#include <iostream>
using namespace std;

void EvenorOdd(int num){

    if(!(num&1)){
        cout<<"Even\n";

    }else{
        cout<<"Odd\n";
    }

}

int main(){
    
    EvenorOdd(5);
    EvenorOdd(4);
    return 0;
}
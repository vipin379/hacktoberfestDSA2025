#include <iostream>
using namespace std;

int SetIthBit(int num , int i){

    int Bit_mask = ~(1<<i);

    num = num&Bit_mask;
    cout<<num;
}


int main(){

    SetIthBit(6 , 1);
    
    return 0;
}
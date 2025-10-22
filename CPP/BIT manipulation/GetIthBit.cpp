#include <iostream>
using namespace std;

int GetIthBit(int num , int i){
    int Bit_mask = 1<<i;

    if(!(num&Bit_mask)){
        return 0;
    }else{
        return 1;
    }
}

int main(){

    cout<<GetIthBit(6 , 2);
    
    return 0;
}
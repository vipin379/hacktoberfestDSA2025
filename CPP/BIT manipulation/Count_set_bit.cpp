#include <iostream>
using namespace std;


void CountSetBit(int num){

    int count = 0 ;

    while(num>0){
        int lastdig = num&1;
        count += lastdig ;

        num = num>>1;
    }

    cout<< count <<endl;
}

int main(){
    
    CountSetBit(10);
    return 0;
}
#include <iostream>
using namespace std;

void clear(int num , int i , int j){

    for (int  m = i; m <= j; m++)
    {
        num = num & (~(1<<m));
    }

    cout<<num<<endl;
    
}

int main(){

    clear(31 , 1 , 3);
    
    return 0;
}
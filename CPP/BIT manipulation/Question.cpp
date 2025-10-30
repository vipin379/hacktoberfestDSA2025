#include <iostream>
using namespace std;

int  update(int num , int i , int value){

    if (value == 0)
    {
        int bitmask = ~(1 << i);

        num = num & bitmask;
        return num;
    }else if (value == 1)
    {
        int bitmask = (1<<i);
        num = num| bitmask;
        return num;
    }
    
    
}

int main(){

    cout<<update(7 , 2 , 0)<<endl;
    cout<<update(7 , 3 , 1)<<endl;

    
    return 0;
}
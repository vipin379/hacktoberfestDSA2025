#include <iostream>
using namespace std;

bool IsPowerOf2(int num){
    if(!(num&(num-1))){
        return true;
    }else{
        return false;
    }
}

int main(){
    
    cout<<IsPowerOf2(8)<<endl;
    cout<<IsPowerOf2(1)<<endl;
    cout<<IsPowerOf2(13)<<endl;
    cout<<IsPowerOf2(83)<<endl;
    return 0;
}
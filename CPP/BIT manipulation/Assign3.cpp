#include <iostream>
using namespace std;

void xorbeauty(int arr[] , int n){

    int nums = 0 ;
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < n;j++)
        {
            for (int k = 0; k < n; k++)
            {
                int beauty = ((arr[i]|arr[j])&arr[k]);
                nums = nums ^ beauty;
            }
            
        }
        
    }

    cout<< nums <<endl;
    
}
int main(){

    int arr[] = {15,45,20,2,34,35,5,44,32,30};
    int n = sizeof(arr)/sizeof(int);

    xorbeauty(arr , n);
    
    return 0;
}
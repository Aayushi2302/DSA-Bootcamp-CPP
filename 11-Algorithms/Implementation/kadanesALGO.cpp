#include<iostream>
using namespace std;

int maxsubarray(int* arr){

    int currsum = 0;
    int maxsum = 0;

    for (int i = 0; i < sizeof(arr); i++)
    {
        currsum = currsum + arr[i];
        if(currsum > maxsum){
            maxsum = currsum;
        }
        if(currsum < 0){
            currsum = 0;
        }
    }
    return maxsum;
    


}

int maxsubarrayneg(int* arr){
    int maxsum = INT8_MIN;

    for (int i = 0; i < sizeof(arr); i++)
    {
        if(arr[i] > maxsum){
            maxsum = arr[i];
        }
    }
    return maxsum;
}

int main()
{
    int arr[5] = {-5, -4, -2, -6, -1};
    int (*FuncPtr)(int*);
    bool if_all_neg = false;
    for(int i = 0; i < sizeof(arr); i++){
        if(arr[i] < 0){
            if_all_neg = true;
        }
        else{
            if_all_neg = false;
        }
    }
    if(if_all_neg == true){
        FuncPtr = maxsubarrayneg;
    }
    else{
        FuncPtr = maxsubarray;
    }
    cout<<FuncPtr(arr)<<endl; 
    
    return 0;
}
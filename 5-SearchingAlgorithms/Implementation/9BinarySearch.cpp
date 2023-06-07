#include<bits/stdc++.h>
using namespace std;
//                         /*starting index*/                                   
int binarySearch(int * arr, int s, int e, int x){ /*key*/
//                                 /*ending index*/         
   if (e >= s)
   {
       int mid = (s + e)/2;

       if (arr[mid] == x)
       {
           return mid;
       }

       if (arr[mid] > x)
       {
           return binarySearch(arr , s , mid - 1 , x);
       }
       else return binarySearch( arr , mid + 1 , e , x);
       
       
   }
   return -1;
   
    
}
int main(){
    // int arr[7] = {1,3,5,6,7,8,9};
    // int arr2[] = { 2, 3, 4, 10, 40 };
    // int size = 7;
    // cout<<binarySearch(arr,0,size - 1,1)<<endl;//0
    // cout<<binarySearch(arr,0,size - 1,3)<<endl;//1
    // cout<<binarySearch(arr,0,size - 1,5)<<endl;//2
    // cout<<binarySearch(arr,0,size - 1,6)<<endl;//3
    // cout<<binarySearch(arr,0,size - 1,7)<<endl;//4
    // cout<<binarySearch(arr,0,size - 1,10)<<endl;//-1
    // cout<<binarySearch(arr,0,size - 1,9)<<endl;//6
    // cout<<binarySearch(arr2,0,4,10)<<endl;//6
    int A[] = {3,4,5,6,7,8};
    cout<<binarySearch(A, 0, 5, 3);
return 0;
}
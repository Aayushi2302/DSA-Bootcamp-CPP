#include<bits/stdc++.h>
using namespace std;

stack<int> sortStack(stack<int> inp){
  stack<int> temps;
  while(!inp.empty()){
    int ele = inp.top();
    inp.pop();
    while(!temps.empty() && temps.top() < ele){
      inp.push(temps.top());
      temps.pop();
    }
    temps.push(ele);
  }
  return temps;
}

void sortArrayfromStack(int* arr, int n){
  stack<int> inp;
  for(int i = 0; i < n; i++){
    inp.push(arr[i]);
  }
  stack<int> tempst = sortStack(inp);

  for(int i = 0; i < n; i++){
    arr[i] = tempst.top();
    tempst.pop();
  }
}

int main(){
  int arr[] = {1, 3, 87, 34, 7, 120};
  int n = sizeof(arr)/sizeof(arr[0]);
  sortArrayfromStack(arr, n);
  for(int i = 0; i < n; i++){
    cout<<arr[i]<<" ";
  }
}

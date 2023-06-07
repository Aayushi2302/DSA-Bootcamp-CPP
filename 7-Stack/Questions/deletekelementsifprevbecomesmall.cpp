#include<bits/stdc++.h>
using namespace std;

void deleteksmallelements(int* arr, int n, int k){
  stack<int> st;
  st.push(arr[0]);
  int count  = 0;

  for(int i = 1; i < n; i++){
    while(!st.empty() && st.top() < arr[i] && count < k){
      st.pop();
      count++;
    }
    st.push(arr[i]);
  }

  int stsize = st.size();
  vector<int> v(stsize);

  while(!st.empty()){
    v[--stsize] = st.top();
    st.pop();
  }
  for(auto x : v){
    cout<<x<<" ";
  }
}

int main(){
  int arr[] = {20, 10, 25, 30, 40};
  int n = sizeof(arr)/sizeof(arr[0]);
  deleteksmallelements(arr, n, 2);
}

#include<bits/stdc++.h>
using namespace std;

void deletemidele(stack<int> &st, int n, int curr = 0){
  if(st.empty() || curr == n){
    return;
  }

  int ele = st.top();   
  st.pop();

  deletemidele(st, n, curr+1);

  if(curr != n/2){
    st.push(ele);
  }
}

int main(){
   stack<int> st;

   st.push(1);
   st.push(2);
   st.push(3);
   st.push(4);
   st.push(5);
   st.push(6);
   st.push(7);
   st.push(8);

   deletemidele(st, st.size());

   while(!st.empty()){
     cout<<st.top()<<endl;
     st.pop();
   }
 }

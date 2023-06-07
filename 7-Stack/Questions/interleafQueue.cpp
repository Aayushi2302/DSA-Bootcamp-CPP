#include<bits/stdc++.h>
using namespace std;

void interleafqueue(queue<int>& q){

  stack<int> tempst;
  if(q.size() % 2 != 0){
    cout<<"Queue is uneven";
    return;
  }

  for(int i = 0; i < q.size()/2; i++){  //pushing first half to stack
    tempst.push(q.front());
    q.pop();
  }
  while(!tempst.empty()){           //enqueing back to queue
    q.push(tempst.top());
    tempst.pop();
  }

  for(int i = 0; i < q.size()/2; i++){     //self dequeue and enqueue
    q.push(q.front());
    q.pop();
  }

  for(int i = 0; i < q.size()/2; i++){        //pushing half to stack
    tempst.push(q.front());
    q.pop();
  }

  while(!tempst.empty()){           //interleafing
    q.push(tempst.top());
    tempst.pop();

    q.push(q.front());    //self enqueue and dequeue
    q.pop();

}
}

int main(){
  queue<int> qu;
  for(int i = 1; i <= 4; i++){
    qu.push(i);
  }
  interleafqueue(qu);
  while(!qu.empty()){
    cout<<qu.front()<<" ";
    qu.pop();
  }
}

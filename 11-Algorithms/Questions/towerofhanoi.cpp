#include<bits/stdc++.h>
using namespace std;

void towerofhanoi(int n, char from, char to, char aux){

  if(n == 1){
    cout<<"Move disc 1 from rod "<<from<<" to rod "<<to<<endl;
    return;
  }
    towerofhanoi(n-1, from, aux, to);
    cout<<"Move disc "<<n<< " from rod"<< from << " to rod "<<to<<endl;
    towerofhanoi(n-1, aux, to, from);
}

int main(){

  int n;
  cout<<"Enter n: ";
  cin>>n;
  towerofhanoi(n, 'A', 'C', 'B');

}

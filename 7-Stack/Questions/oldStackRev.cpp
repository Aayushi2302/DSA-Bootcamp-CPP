#include<iostream>
#include <stack>
using namespace std;

stack<int> st;
stack<int> tempst;
void reverse(int index){
	if(st.empty()){
		return;
	}

	int item = st.top();
	st.pop();
	reverse(index+1);
	tempst.push(item);
	if(index == 0){
		while(!tempst.empty()){
			st.push(tempst.top());
			tempst.pop();
		}
	}
}



int main(){
	int i = 1;
	while(i <= 5){
		st.push(i);
		i++;
	}
	while(!st.empty()){
		cout<<st.top()<<endl;
		st.pop();
	}
	i = 1;
	while(i <= 5){
		st.push(i);
		i++;
	}
	reverse(0);
	while(!st.empty()){
		cout<<st.top()<<endl;
		st.pop();
	}
}


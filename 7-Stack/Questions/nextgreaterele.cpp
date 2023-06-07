#include<bits/stdc++.h>

using namespace std;

stack<int> st;

void nextgreater(int* arr, int n){
	for(int i = 0; i < n; i++){
		if(st.empty()){
			st.push(arr[i]);
			continue;
		}
		if(arr[i] > st.top()){
			cout<< st.top() << " -> " << arr[i]<<endl;
			st.pop();
			st.push(arr[i]);
		}
		else{
			st.push(arr[i]);
		}
	}

	while(!st.empty()){
		cout<<st.top()<<" -> -1"<<endl;
		st.pop();
	}

}

void nextgreatersorted(int* arr, int n){
	for(int i = n-1; i >= 0; i--){
		if(st.empty()){
			st.push(arr[i]);
			continue;
		}
		if(arr[i] > st.top()){
			cout<< st.top() << " -> " << arr[i]<<endl;
			st.pop();
			st.push(arr[i]);
		}
		else{
			st.push(arr[i]);
		}
	}

	while(!st.empty()){
		cout<<st.top()<<" -> -1"<<endl;
		st.pop();
	}

}

int main(){

	int arr[] = { 11, 13, 21, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	nextgreatersorted(arr, n);
	cout<<endl;
	nextgreater(arr, n);

}
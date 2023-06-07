#include<bits/stdc++.h>
using namespace std;

stack<int> st;
string pfix;

int precedence(char x){
	if(x == '^')
		return 3;
	else if(x == '/' || x == '*')
		return 2;
	else if(x == '+' || x == '-')
		return 1;
	else
		return -1;

}

void infixtopostfix(string infix){
	for(int i = 0; i < infix.length(); i++){
		if((infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= '0' && infix[i] <= '9'))
			pfix += infix[i];
		else if(infix[i] == '('){
			st.push(infix[i]);
		}
		else if(infix[i] == ')'){
			while(st.top() != '('){
				pfix += st.top();
				st.pop();
			}
			st.pop();
		}

		else{
			while(!st.empty() && precedence(infix[i]) <= precedence(st.top())){
			pfix += st.top();
			st.pop();
		}
		st.push(infix[i]);
	}
}

while(!st.empty()){
	pfix += st.top();
	st.pop();
}
}

int main(){
	string infix = "a+b*(c^d-e)^(f+g*h)-i";
	infixtopostfix(infix);
	cout<<pfix<<endl;
}

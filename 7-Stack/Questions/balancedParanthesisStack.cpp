#include<bits/stdc++.h>
using namespace std;

stack<char> st;
string str;
char c;

bool balancedparaCheck(int n){
	for(int i = 0; i < n; i++){
		if(str[i] == '(' || str[i] == '{' || str[i] == '['){
			st.push(str[i]);
		}

		if(st.empty()){
			return false;
		}

		switch(str[i]){
			case ')':
				c = st.top();
				st.pop();
				if(c == '{' || c == '['){
					return false;
				}
				break;
			

			case ']':
				c = st.top();
				st.pop();
				if(c == '{' || c == '('){
					return false;
				}
				break;
			

			case '}':
				c = st.top();
				st.pop();
				if(c == '(' || c == '['){
					return false;
				}
				break;
			
		}
	}
	return (st.empty());
}

int main(){
	str = "{()}[]";
	int n = sizeof(str) / sizeof(str[0]);
	bool res = balancedparaCheck(n);

	if (res)
        cout << "Balanced";
    else
        cout << "Not Balanced";
}
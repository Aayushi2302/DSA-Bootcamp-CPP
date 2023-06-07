#include<bits/stdc++.h>

using namespace std;

class StackNode{
public:
	int data;
	StackNode* next;
};

void push(StackNode** root, int value){
	StackNode* n = new StackNode();
	StackNode* curr = (*root);

	n->data = value;
	n->next = (*root);
	(*root) = n;


	

}

bool isEmpty(StackNode* root){
	return !root;
}

int pop(StackNode** root){
	if(isEmpty(*root)){
		return INT_MIN;
	}
	StackNode* temp = (*root);
	(*root) = (*root)->next;
	int data = temp->data;
	free(temp);
	return data;
}

int peek(StackNode** root){
	if(isEmpty(*root)){
		return INT_MIN;
	}
	return (*root)->data;
}

int main(){

	StackNode* root = NULL;
	push(&root, 1);
	push(&root, 2);
	push(&root, 3);
	push(&root, 4);
	push(&root, 5);
	cout<<"Current Top element in stack is: "<<peek(&root)<<endl;
	cout<<pop(&root)<<" Popped from stack"<<endl;
	cout<<"Current Top element in stack is: "<<peek(&root)<<endl;
	cout<<"Elements present in stack are: ";
	while(!isEmpty(root)){
		cout<<peek(&root)<<" ";
		pop(&root);
	}


}
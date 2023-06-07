#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
};

void append(Node* head, int value){
	Node* n = new Node();
	Node* curr = head;

	n->data = value;
	n->next = NULL;
	if(curr == NULL){	
		head = n;
		return;
	}
	
	while(curr->next != NULL){
		curr = curr->next;
	}

	curr->next = n;

}

void display(Node* head){
	Node* curr = head;
	while(curr->next != NULL){
		cout<<curr->data<<endl;
		curr = curr->next;
	}
}

int main(){

	Node* head = NULL;
	append(head, 1);
	append(head, 2);
	append(head, 3);
	append(head, 4);
	append(head, 5);
	append(head, 6);
	append(head, 7);
	display(head);

	return 0;
}
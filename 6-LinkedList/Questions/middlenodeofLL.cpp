#include <iostream>

using namespace std;

class Node{
public:
	int data;
	Node* next;
};

void append(Node** head_ref, int value){
	Node* n = new Node();
	Node* curr = (*head_ref);
	n->data = value;
	n->next = NULL;

	if((*head_ref) == NULL){
		(*head_ref) = n;
		return;
	}

	while(curr->next != NULL){
		curr = curr->next;
	}
	curr->next = n;

}

void display(Node* head){
	Node* n = head;
	while(n != NULL){
		cout<<n->data<<endl;
		n = n->next;
	}
}

void midnode(Node** head_ref){
	Node* ref_ptr = (*head_ref);
	Node* main_ptr = (*head_ref);
	if((*head_ref) == NULL){
		cout<<"Linked list is empty";
		return;
	}
	else{
		while(ref_ptr != NULL && ref_ptr->next != NULL){
			ref_ptr = ref_ptr->next->next;
			main_ptr = main_ptr->next;
		}
	}
	cout<<"The mid node is: "<<main_ptr->data;
}

int main(){
	Node* head = NULL;
	append(&head, 1);
	append(&head, 2);
	append(&head, 3);
	append(&head, 4);
	append(&head, 5);
	append(&head, 6);
	display(head);
	cout<<endl;
	midnode(&head);
	return 0;
}
#include<iostream>

using namespace std;

class Node{
public:
	int data;
	Node* next;
	int flag;
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

void reverse(Node** head_ref){
	Node* curr = (*head_ref);
	Node* temp = NULL;
	while(curr->next != NULL){
		(*head_ref) = curr->next;
		curr->next = temp;
		temp = curr;
		curr = (*head_ref);
	}
	(*head_ref)->next = temp;
}

bool palindromeCheck(Node** head_ref){
	Node* main_ptr = (*head_ref);
	Node* ref_ptr = (*head_ref);
	while(ref_ptr != NULL){
		ref_ptr = ref_ptr->next;
		main_ptr = main->next->next;
	}
	int data = main_ptr->data;
	reverse(&main_ptr);
}

int main(){
	Node* head = NULL;
	//Node* obj = new Node();

	append(&head, 1);
	append(&head, 2);
	append(&head, 3);
	append(&head, 4);
	append(&head, 5);
	append(&head, 6);
	display(head);
	//reverse(&head);
	//display(head);

	return 0;
}
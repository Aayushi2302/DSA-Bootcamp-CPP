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


void nthfromendsimple(Node** head_ref, int index){
	Node* curr = (*head_ref);
	int count = 0;
	while(curr != NULL){
		curr = curr->next;
		count++;
	}
	curr = (*head_ref);
	for(int i = 1; i <= (count - index) && curr != NULL; ++i){
		curr = curr->next;
	}
	cout<<curr->data;
}

void nthfromendtwopointer(Node** head_ref, int index){
	Node* main_ptr = (*head_ref);
	Node* ref_ptr = (*head_ref);

	for(int i = 1; i < index && ref_ptr != NULL; ++i){
		ref_ptr = ref_ptr->next;
	}

	while(ref_ptr->next != NULL){
		ref_ptr = ref_ptr->next;
		main_ptr = main_ptr->next;
	}

	cout<<main_ptr->data;


}




int main(){
	Node* head = NULL;
	append(&head, 1);
	append(&head, 2);
	append(&head, 3);
	append(&head, 4);
	append(&head, 5);
	display(head);
	cout<<endl;
	nthfromendsimple(&head, 2);
	nthfromendtwopointer(&head, 2);

}


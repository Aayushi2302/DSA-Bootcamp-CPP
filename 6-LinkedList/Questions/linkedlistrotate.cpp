#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};

void display(struct Node* n){
	while(n!=NULL){
		printf("%d\n", n->data);
		n = n->next;
	}
}

void append(struct Node** head_ref, int value){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	struct Node* last = (*head_ref);

	n->data = value;
	n->next = NULL;

	if((*head_ref) == NULL){
		(*head_ref) = n;
		return;
	}

	while(last->next !=NULL){
		last = last->next;
	}

	last->next = n;
}

void rotate(struct Node** head_ref, int k){
	struct Node* curr = (*head_ref);
	int count = 0;
	while(count < k && curr != NULL){
		curr = curr->next;
		count++;
	}
	if(curr == NULL){
		return;
	}
	
	Node* knode = curr;

	while(curr->next != NULL){
		curr = curr->next;
	}

	curr->next = (*head_ref);
	(*head_ref) = knode->next;

	knode->next = NULL;
}

int main(){

	struct Node* head = NULL;

	append(&head, 1);
	append(&head, 2);
	append(&head, 3);
	append(&head, 4);
	append(&head, 5);
	append(&head, 6);
	display(head);
	printf("\n");
	rotate(&head, 2);
	display(head);

	return 0;
}
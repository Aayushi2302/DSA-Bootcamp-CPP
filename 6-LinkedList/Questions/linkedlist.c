#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};


void push(struct Node** head_ref, int value){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = value;
	n->next = (*head_ref);
	(*head_ref) = n;

}

void insertAfter(struct Node* prev_n, int value){
	if(prev_n == NULL){
		printf("Cannot be null!!");
		return;
	}
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = value;
	n->next = prev_n->next;
	prev_n->next = n;
}

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

void delete(struct Node** head_ref, int key){
	struct Node* temp = *head_ref, *prev_n;

	if(temp != NULL && temp->data == key){
		*head_ref = temp->next;
		free(temp);
		return;
	}

	while(temp != NULL && temp->data != key){
		prev_n = temp;
		temp = temp->next;
	}

	if(temp == NULL){
		return;
	}

	prev_n->next = temp->next;
	free(temp);


}

void deleteAtPos(struct Node** head_ref, int pos){
	struct Node *temp = *head_ref;
	if(pos == 0){
		(*head_ref) = temp->next;
		free(temp);
		return;
	}

	for (int i = 0; i < pos-1 && temp !=NULL; ++i)
	{
		temp = temp->next;
	}

	if(temp == NULL || temp->next == NULL){
		return;
	}

	struct Node* next = temp->next->next;
	free(temp->next);
	temp->next = next;
}

void deleteAll(struct Node** head_ref){
	struct Node* curr = (*head_ref);
	struct Node* next;

	while(curr != NULL){
		next = curr->next;
		free(curr);
		curr = next;
	}
	printf("Linked List deleted successfully!!!");
}


int main(){

	struct Node* head = NULL;

	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	insertAfter(head->next, 4);
	append(&head, 5);
	delete(&head, 2);
	display(head);
	deleteAtPos(&head, 2);
	display(head);
	deleteAll(&head);


}

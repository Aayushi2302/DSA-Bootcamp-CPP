#include<stdio.h>
#include<stdlib.h>

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

int length(struct Node** head_ref){
	int count = 0;
	struct Node* curr = (*head_ref);
	while(curr != NULL){
		curr = curr->next;
		count++;
	}
	free(curr);
	return count;
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
	int len = length(&head);
	printf("The length of the linked list is: %d", len);
}
